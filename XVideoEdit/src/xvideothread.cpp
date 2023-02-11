/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:29
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-07 08:52:57
 * @FilePath: /XVideoEdit/src/xvideothread.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideothread.h"
#include "XFilter.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <ostream>

using namespace cv;


static VideoCapture cap1;
static VideoCapture cap2;
static bool isExit = false;
static VideoWriter vw;

XVideoThread::XVideoThread()
{
    start();
}

XVideoThread::~XVideoThread(){
    mutex.lock();
    isExit=true;
    mutex.unlock();
    wait();
    quit();
}

bool XVideoThread::Open(const std::string file){
    Seek(0);
    std::cout<<"opened file1: "<<file<<std::endl;
    mutex.lock();
    bool re = cap1.open(file);
    mutex.unlock();
    // std::cout<<"re: "<<re<<std::endl;
    if(!re){
        return re;
    }
    
    this->width = cap1.get(CAP_PROP_FRAME_WIDTH);
    this->high = cap1.get(CAP_PROP_FRAME_HEIGHT);
    fps = cap1.get(CAP_PROP_FPS);
    if(fps <= 0) fps =25;
    src1file=file;
    this->totalMs = ((double)cap1.get(CAP_PROP_FRAME_COUNT)/(double)fps)*1000;
    return true;
}
bool XVideoThread::Open2(const std::string file){
    Seek(0);
    std::cout<<"opened file2: "<<file<<std::endl;
    mutex.lock();
    bool re = cap2.open(file);
    mutex.unlock();
    std::cout<<"re: "<<re<<std::endl;
    if(!re){
        return re;
    }
    
    this->width2 = cap2.get(CAP_PROP_FRAME_WIDTH);
    this->high2 = cap2.get(CAP_PROP_FRAME_HEIGHT);

    // fps = cap2.get(CAP_PROP_FPS);
    // if(fps <= 0) fps =25;
    return true;
}

void XVideoThread::run(){
    Mat mat1;
    Mat mat2;
    while(true){
        mutex.lock();
        if(isExit){
            mutex.unlock();
            break;
        }
        // 判断视频是否打开
        if(!cap1.isOpened()){
            mutex.unlock();
            msleep(5);
            continue;
        }
        if(!isPlay){
            mutex.unlock();
            msleep(5);
            continue;
        }

        // 阶段结束位置
        int cur = cap1.get(CAP_PROP_POS_FRAMES);
        // 读一帧视频，解码并颜色转换
        if((end>0 && cur>=end )|| !cap1.read(mat1)||mat1.empty()){
            mutex.unlock();
            // 最后一帧，主动释放
            if(isWrite){
                StopSave();
                // 传给前端信号
                SaveEnd();
            }
            msleep(5);
            continue;
        }

        // 视频源2
        if(cap2.isOpened()){
            cap2.read(mat2);
        }

        // 显示图像1
        if(!isWrite){
            ViewImage1(mat1);
            if(!mat2.empty()){
                ViewImage2(mat2);
            }
        }
        

        // 通过过滤器处理视频
        Mat dst = XFilter::Get()->Filter(mat1, mat2, mark);
        // 显示处理后图像
        if(!isWrite){
            ViewDst(dst);
        }
        int s=0;
        s=1000/fps;
        if(isWrite){
            s=0;
            vw.write(dst);
        }
        
        mutex.unlock();
        // std::cout<<"------s :"<<s<<std::endl;
        msleep(s);
    }
}

bool XVideoThread::IsGetfile(){
    mutex.lock();
    if(cap1.isOpened()){
        mutex.unlock();
        msleep(5);
        return true;
    }
    mutex.unlock();
    return false;
}

void XVideoThread::SetBegin(double p){
    mutex.lock();
    double count = cap1.get(CAP_PROP_FRAME_COUNT);
    int frame = p*count;
    this->begin=frame; 
    mutex.unlock();
}
void XVideoThread::SetEnd(double p){
    mutex.lock();
    double count = cap1.get(CAP_PROP_FRAME_COUNT);
    int frame = p*count;
    this->end=frame;
    mutex.unlock();
}

/**
 * @description:
 * @return {*}
 */
double XVideoThread::GetPos(){
    
    double pos = 0;
    mutex.lock();        // bug 加锁之后阻塞
    if(!cap1.isOpened()){
        mutex.unlock();
        return pos;
    }

    double count = cap1.get(CAP_PROP_FRAME_COUNT);
    double cur = cap1.get(CAP_PROP_POS_FRAMES);
    if(count>0.001){
        pos = cur/count;
    }
    mutex.unlock();
    return pos;
}

bool XVideoThread::Seek(int frame){
    mutex.lock();
    if(!cap1.isOpened()){
        mutex.unlock();
        return false;
    }   
    int re = cap1.set(CAP_PROP_POS_FRAMES,frame);
    if(cap2.isOpened()){
        cap2.set(CAP_PROP_POS_FRAMES,frame);
    }
    mutex.unlock();
    return re;
}

bool XVideoThread::Seek(double pos){
    double count = cap1.get(CAP_PROP_FRAME_COUNT);
    int frame = pos * count;
    // 调用另一个Seek函数
    return Seek(frame);
    
}

bool XVideoThread::StartSave(const std::string filename, int width, int height,bool isColor){
    std::cout<<"开始导出"<<std::endl;
    // 从头开始导出
    Seek(begin);
    mutex.lock();
    if(!cap1.isOpened()){
        mutex.unlock();
        std::cout<<"视频未打开！"<<std::endl;
        return false;
    }
    if(width<=0){
        width=cap1.get(CAP_PROP_FRAME_WIDTH);
    }
    if(height<=0){
        height=cap1.get(CAP_PROP_FRAME_HEIGHT);
    }
    // 改变状态
    this->isWrite=true;
    // 自动导出，不用按播放键
    this->isPlay=true;

    vw.open(filename,
        VideoWriter::fourcc('X', '2', '6', '4'),
        this->fps,
        Size(width,height),
        isColor
    );
    if(!vw.isOpened()){
        std::cout<<"start save failed!"<<std::endl;
        mutex.unlock();
        return false;
    }
    DstFile = filename;
    mutex.unlock();
    return true;
}

void XVideoThread::StopSave(){
    std::cout<<"停止导出"<<std::endl;
    mutex.lock();
    vw.release();
    isWrite=false;
    mutex.unlock();
}

void XVideoThread::Play(){
        mutex.lock();
        isPlay=true;
        mutex.unlock();
}
void XVideoThread::Pause(){
    mutex.lock();
    isPlay=false;
    mutex.unlock();
}

void XVideoThread::SetMark(Mat m){
    mutex.lock();
    this->mark=m;
    mutex.unlock();
}