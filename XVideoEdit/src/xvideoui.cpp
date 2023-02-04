/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: Ruomio 1065940593@qq.com
 * @LastEditTime: 2023-02-04 15:47:46
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
static bool isExport = false;

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
    // 导出完成
    QObject::connect(XVideoThread::Get(),
        SIGNAL(SaveEnd()),
        this,
        SLOT(ExprotEnd())
    );

    // 定时器
    startTimer(43);
    // 默认隐藏暂停按键
    ui->pauseButton->hide();
    // 默认暂停
    Pause();
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

    if(ui->rotateBox->currentIndex()==1){
        XFilter::Get()->Add(XTask {XTASK_ROTATE90});
    }
    if(ui->rotateBox->currentIndex()==2){
        XFilter::Get()->Add(XTask {XTASK_ROTATE180});
    }
    if(ui->rotateBox->currentIndex()==3){
        XFilter::Get()->Add(XTask {XTASK_ROTATE270});
    }
}

void XVideoUI::Export(){
    
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

void XVideoUI::ExprotEnd(){
    isExport=false;
    ui->exportButton->setText("start Export");
}

void XVideoUI::Play(){
    // 未打开视频文件时按钮不响应
    if(!XVideoThread::Get()->IsGetfile()){
        return;
    }
    ui->pauseButton->show();
    // 将暂停建位置移动到播放键
    ui->pauseButton->setGeometry(ui->playButton->geometry());
    XVideoThread::Get()->Play();
    ui->playButton->hide();
}
void XVideoUI::Pause(){
    ui->playButton->show();
    XVideoThread::Get()->Pause();
    ui->pauseButton->hide();
}