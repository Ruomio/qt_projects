/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 10:51:11
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-12 15:31:33
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

void MatView::SetImage(cv::Mat mat){
    if(img.isNull()){
        uchar *buff = new uchar[width()*height()*3];
        img = QImage(buff,width(),height(),QImage::Format_BGR888);
    }
    // 缩放图像到播放窗口大小，经处理后的图像，并展示
    Mat dst;
    cv::resize(mat, dst, Size(img.size().width(),img.size().height()));
    // 将mat中数据复制到QImage的img 中
    memcpy(img.bits(),dst.data,dst.cols*dst.rows*dst.elemSize());
    // update调用paintevent函数
    update();
}