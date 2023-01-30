/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:41:41
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 09:33:15
 * @FilePath: /XVideoEdit/src/xvideowidget.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideowidget.h"
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
    if(img.isNull()){
        uchar *buff = new uchar[width()*height()*3];
        img = QImage(buff,width(),height(),QImage::Format_BGR888);
    }
    Mat des;
    cv::resize(mat, des, Size(img.size().width(),img.size().height()));

    memcpy(img.bits(),des.data,des.cols*des.rows*des.elemSize());
    update();
}