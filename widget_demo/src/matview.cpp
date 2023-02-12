/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 10:51:11
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-12 11:27:13
 * @FilePath: /widget_demo/matview.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "matview.h"
#include <qthread.h>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <QImage>
#include <QPainter>
#include <qimage.h>
#include <iostream>
#include <qnamespace.h>
#include <qpoint.h>

using namespace cv;
using namespace std;

void MatView::paintEvent(QPaintEvent *e){
   
    QPainter p;
    p.begin(this);
    p.drawImage(QPoint(0,0),img);
    p.end();
}

MatView::MatView(QWidget *p):QOpenGLWidget(p)
{
   
}


MatView::~MatView(){
    
}

// void MatView::Update(){
//     XVideoThread::Get()->CapShow();
//     Mat mat = XVideoThread::Get()->mat;
//     QImage img(mat.data,mat.cols,mat.rows,QImage::Format_BGR888);
//     update();
// }
