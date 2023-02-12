/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-11 12:49:47
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-11 14:31:45
 * @FilePath: /widget_demo/src/XVideoThread.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XVideoThread.h"
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv; 

static VideoCapture cap1;


XVideoThread::XVideoThread()
{   
    start();
}

XVideoThread::~XVideoThread()
{
    mutex.lock();
    mutex.unlock();
    wait();
    quit();
}

bool XVideoThread::Open(const std::string file){
    cout<<"opened filed path: "<<file<<endl;
    mutex.lock();
    bool res = cap1.open(file);
    mutex.unlock();
    if(!res){
        return false;
    }
    this->width=cap1.get(CAP_PROP_FRAME_WIDTH);
    this->height=cap1.get(CAP_PROP_FRAME_HEIGHT);
    this->fps=cap1.get(CAP_PROP_FPS);
    if(fps<=0){
        fps=30;
    }
    return true;

}