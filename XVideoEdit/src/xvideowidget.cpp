/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:41:41
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-05 09:10:00
 * @FilePath: /XVideoEdit/src/xvideowidget.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideowidget.h"
#include <opencv2/core/hal/interface.h>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <QImage>
#include <QPainter>
#include <qevent.h>
#include <qimage.h>
using namespace cv;

XVideoWidget::XVideoWidget(QWidget *p):QOpenGLWidget(p){

}

XVideoWidget::~XVideoWidget(){

}

void XVideoWidget::paintEvent(QPaintEvent *e){
    QPainter p;
    p.begin(this);
    p.drawImage(QPoint(0,0),img);
    p.end();
}

void XVideoWidget::SetImage(cv::Mat mat){
    // 转灰度图要改变内存结构
    QImage::Format fmt = QImage::Format_BGR888;
    int pixsize = 3;
    if(mat.type() == CV_8UC1){
        fmt = QImage::Format_Grayscale8;
        pixsize=1;
    }
    
    if(img.isNull() || img.format() != fmt){
        delete img.bits();
        uchar *buff = new uchar[width()*height()*pixsize];
        img = QImage(buff,width(),height(),fmt);
    }
    Mat des;
    cv::resize(mat, des, Size(img.size().width(),img.size().height()));

    memcpy(img.bits(),des.data,des.cols*des.rows*des.elemSize());
    update();
}