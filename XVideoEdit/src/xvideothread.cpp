/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:29
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 11:07:31
 * @FilePath: /XVideoEdit/src/xvideothread.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideothread.h"
#include <opencv2/videoio.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;


static VideoCapture cap1;
static bool isExit = false;

XVideoThread::XVideoThread()
{
    start();
}

XVideoThread::~XVideoThread(){
    mutex.lock();
    isExit=true;
    mutex.unlock();
}

bool XVideoThread::Open(const std::string file){
    std::cout<<"file: "<<file<<std::endl;
    mutex.lock();
    bool re = cap1.open(file);
    mutex.unlock();
    std::cout<<"re: "<<re<<std::endl;
    if(!re){
        return re;
    }
    fps = cap1.get(CAP_PROP_FPS);
    if(fps <= 0) fps =25;
    return true;
}

void XVideoThread::run(){
    Mat mat1;
    while(true){
        // 判断视频是否打开
        mutex.lock();
        if(isExit){
            mutex.unlock();
            break;
        }
        if(!cap1.isOpened()){
            mutex.unlock();
            msleep(5);
            continue;
        }
        // 读一帧视频，解码并颜色转换
        if(!cap1.read(mat1)||mat1.empty()){
            mutex.unlock();
            msleep(5);
            continue;
        }
        // 显示图像
        ViewImage1(mat1);
        // msleep(41);
        int s=0;
        s=1000/fps;
        msleep(s);
        mutex.unlock();
    }
}

double XVideoThread::GetPos(){
    
    double pos = 0;
    // mutex.lock();        // bug 加锁之后阻塞
    if(!cap1.isOpened()){
        // mutex.unlock();
        return pos;
    }
    double count = cap1.get(CAP_PROP_FRAME_COUNT);
    double cur = cap1.get(CAP_PROP_POS_FRAMES);
    if(count>0.001){
        pos = cur/count;
    }

    // mutex.unlock();
    
    return pos;
}