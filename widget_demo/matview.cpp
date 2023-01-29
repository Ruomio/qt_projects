/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 10:51:11
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-29 16:18:18
 * @FilePath: /widget_demo/matview.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "matview.h"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <QImage>
#include <QPainter>

using namespace cv;

void MatView::paintEvent(QPaintEvent *e){
    Mat src = imread("/home/papillon/Documents/All_Code/OpenCv/学习Demo源码/opencv_tutorial_data/images/ttt.png");
    QImage img(src.datastart, src.cols, src.rows, src.step ,QImage::Format_BGR888);
    QPainter painter;
    painter.begin(this);
    painter.drawImage(QPoint(0,0),img);
    
    // imshow("xserver",src);
    // waitKey(0);
}

MatView::MatView(QWidget *p):QOpenGLWidget(p)
{
   
}


MatView::~MatView(){
    
}