/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: Ruomio 1065940593@qq.com
 * @LastEditTime: 2023-02-02 19:49:32
 * @FilePath: /XVideoEdit/src/xvideoui.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideoui.h"
#include "./ui_xvideoui.h"
#include "XFilter.h"
#include "xvideothread.h"
#include "xvideowidget.h"
#include <opencv4/opencv2/core.hpp>
#include <QFileDialog>
#include <qdialog.h>
#include <qfiledialog.h>
#include <QMessageBox>
#include <qobject.h>
#include <qobjectdefs.h>
#include <string>
#include <iostream>
using namespace std;

static bool pressSlider=false;

XVideoUI::XVideoUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XVideoUI)
{
    ui->setupUi(this);

    // 信号与槽关联
    qRegisterMetaType<cv::Mat>("cv::Mat");
    // 原始视频
    QObject::connect(XVideoThread::Get(),
        SIGNAL(ViewImage1(cv::Mat)),
        ui->src1,
        SLOT(SetImage(cv::Mat))
    );
    // 处理后视频
    QObject::connect(XVideoThread::Get(),
        SIGNAL(ViewDst(cv::Mat)),
        ui->dst,
        SLOT(SetImage(cv::Mat))
    );

    // 定时器
    startTimer(43);
}

XVideoUI::~XVideoUI()
{
    delete ui;
}

void XVideoUI::Open(){
    QString name = QFileDialog::getOpenFileName(this,"select video file!");
    if(name.isEmpty())  return;
    string file = name.toLocal8Bit().data();
    if(!XVideoThread::Get()->Open(file)){
        QMessageBox::information(0,"error",name+" open failed!");    //0表示没有父类，不会继承控件样式 
        return;
    }

}
void XVideoUI::timerEvent(QTimerEvent *e){
    if(pressSlider) return;
    double pos = XVideoThread::Get()->GetPos();
    ui->playSlider->setValue(int(pos*1000));
}

void XVideoUI::SliderPress(){
    pressSlider=true;
}

void XVideoUI::SliderRelease(){
    pressSlider=false;
}

void XVideoUI::SetPos(int pos){
    XVideoThread::Get()->Seek((double)pos/1000.);
}

void XVideoUI::Set(){
    // 先清理
    XFilter::Get()->Clear();
    // 对比度和亮度
    
    if(ui->bright->value() >0 || ui->contrast->value() >1 ){
        XFilter::Get()->Add(XTask{XTASK_GAIN, {(double)ui->bright->value(),ui->contrast->value()}});
    }
}

void XVideoUI::Export(){
    static bool isExport = false;
    if(isExport){
        XVideoThread::Get()->StopSave();
        isExport=false;
        ui->exportButton->setText("start Export");
        return;
    }
    QString name = QFileDialog::getSaveFileName(this,"save","out1.avi");
    std::string filename = name.toLocal8Bit().data();
    if(XVideoThread::Get()->StartSave(filename)){
        isExport=true;
        ui->exportButton->setText("stop Export");
    }
}
