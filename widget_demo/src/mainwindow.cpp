/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-28 20:36:56
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-16 15:04:21
 * @FilePath: /widget_demo/mainwindow.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "XVideoThread.h"
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/videoio.hpp>
#include <qglobal.h>
#include <qnamespace.h>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
   
    // 信号和槽关联
    qRegisterMetaType<cv::Mat>("cv::Mat");
    QObject::connect(XVideoThread::Get(),
        SIGNAL(ViewVideo(cv::Mat)),
        ui->src,
        SLOT(SetImage(cv::Mat))
    );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open(){
    QString name = QFileDialog::getOpenFileName(this,"select video file!");
    if(name.isEmpty())  return;
    string file = name.toLocal8Bit().data();
    if(!XVideoThread::Get()->Open(file)){
        QMessageBox::information(0,"error",name+" open failed!");    //0表示没有父类，不会继承控件样式 
        return;
    }
}

void MainWindow::OpenCap(){
    VideoCapture vc = VideoCapture(0);
    if(!vc.isOpened()){
        cout<<"打开摄像头失败！"<<endl;
        return;
    }
    cout<<"打开摄像头成功 ！"<<endl;

    if(!XVideoThread::Get()->OpenCap(vc)){
        QMessageBox::information(0,"error"," open cap failed!");
        return;
    }
}