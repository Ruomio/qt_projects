/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 10:51:11
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-04-01 13:47:40
 * @FilePath: /widget_demo/matview.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "matview.h"
#include "MatPro.h"
#include <opencv4/opencv2/videoio.hpp>
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
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc/imgproc_c.h>
// #include <opencv4/opencv2/freetype.hpp>

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
    // cout<<"In SetImage()"<<endl;

    // 图像预处理，减少计算量
    Mat afterProcess;
    afterProcess = MatPro::Get()->preProcess(mat);

    // 检测是否加载人脸模型
    if(MatPro::Get()->model->empty()){
        cout<<"模型为空！正在训练"<<endl;
        MatPro::Get()->faceTrain();
    }
    
    // 预测
    double alpha_w = (double)mat.cols/300;
    double alpha_h = (double)mat.rows/300;
    cv::resize(afterProcess,afterProcess,Size(300,300));
    // cout<<afterProcess.cols<<endl<<afterProcess.rows<<endl;
    int predic = MatPro::Get()->model->predict(afterProcess);
    cout<<predic<<endl;
    
    // 检测人脸并框选
    MatPro::Get()->detectFace(mat, afterProcess, predic, alpha_w, alpha_h);




    if(this->img.isNull()){
        uchar *buff = new uchar[width()*height()*3];
        this->img = QImage(buff,width(),height(),QImage::Format_BGR888);
    }
    // 缩放图像到播放窗口大小，经处理后的图像，并展示
    Mat dst;
    cv::resize(mat, dst, Size(this->img.size().width(),this->img.size().height()));
    // 将dst中数据复制到QImage的img 中
    memcpy(this->img.bits(),dst.data,dst.cols*dst.rows*dst.elemSize());

    // 释放内存
    afterProcess.release();
    dst.release();

    // update调用paintevent函数
    update();
}

