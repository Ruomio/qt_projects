/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:29
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 08:27:28
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

XVideoThread::XVideoThread()
{

}

XVideoThread::~XVideoThread(){

}

bool XVideoThread::Open(const std::string file){
    std::cout<<"file: "<<file<<std::endl;
    bool re = cap1.open(file);
    std::cout<<"re: "<<re<<std::endl;
    return re;
}

void XVideoThread::run(){

}