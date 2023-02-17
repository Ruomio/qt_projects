/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-16 15:11:29
 * @FilePath: /XVideoEdit/src/xvideoui.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideoui.h"
#include "./ui_xvideoui.h"
#include "XAudio.h"
#include "XFilter.h"
#include "xvideothread.h"
#include "xvideowidget.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
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
static bool isColor = true;
static bool isMark = false;
static bool isBlend = false;
static bool isMerge = false;

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
    QObject::connect(XVideoThread::Get(),
        SIGNAL(ViewImage2(cv::Mat)),
        ui->src2,
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
    Play();
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
void XVideoUI::Left(int pos){
    XVideoThread::Get()->SetBegin((double)pos/1000.);
    // SetPos(pos);
}
void XVideoUI::Right(int pos){
    XVideoThread::Get()->SetEnd((double)pos/1000.);
}

void XVideoUI::Set(){
    // 先清理
    XFilter::Get()->Clear();
    isColor=true;

    // 视频裁剪
    bool isClip = false;
    int cx = ui->clip_x->value();
    int cy = ui->clip_y->value();
    int cw = ui->clip_width->value();
    int ch = ui->clip_high->value();
    if(cx+cy+cw+ch>0){
        isClip=true;
        XFilter::Get()->Add(XTask {XTASK_CLIP,{(double)cx,(double)cy,(double)cw,(double)ch}});
        // 变换尺寸与原尺寸一致
        XFilter::Get()->Add(XTask{XTASK_RESIZE,{(double)XVideoThread::Get()->width,(double )XVideoThread::Get()->high}});
    }

    // 图像金字塔
    bool isPy = false;
    if(!isClip && ui->pydowm->value()>0){
        isPy=true;
        XFilter::Get()->Add(XTask{XTASK_PYDOWN,{(double)ui->pydowm->value()}});
        int w = XVideoThread::Get()->width;
        int h = XVideoThread::Get()->high;
        for(int i=0; i<ui->pydowm->value();i++){
            w/=2;
            h/=2;
        }
        ui->width->setValue(w);
        ui->high->setValue(h);
    }
    if(!isClip && ui->pyup->value()>0){
        isPy=true;
        XFilter::Get()->Add(XTask{XTASK_PYUP,{(double)ui->pyup->value()}});
        int w = XVideoThread::Get()->width;
        int h = XVideoThread::Get()->high;
        for(int i=0; i<ui->pyup->value();i++){
            w*=2;
            h*=2;
        }
        ui->width->setValue(w);
        ui->high->setValue(h);
    }
    
    // 尺寸调整
    if(!isMerge&&!isClip && !isPy && ui->width->value()>0 && ui->high->value()>0){
        XFilter::Get()->Add(XTask{XTASK_RESIZE,{(double)ui->width->value(),(double )ui->high->value()}});
    }

    // 颜色调整
    if(ui->colorBox->currentIndex()==1){
        XFilter::Get()->Add(XTask {XTASK_GRAY});
        isColor = false;
    }
    if(ui->colorBox->currentIndex()==2){
        XFilter::Get()->Add(XTask {XTASK_BINARY});
    }
    
    // 对比度和亮度
    if(ui->bright->value() >0 || ui->contrast->value() >1 ){
        XFilter::Get()->Add(XTask{XTASK_GAIN, {(double)ui->bright->value(),ui->contrast->value()}});
    }

    //旋转
    if(ui->rotateBox->currentIndex()==1){
        XFilter::Get()->Add(XTask {XTASK_ROTATE90});
    }
    else if(ui->rotateBox->currentIndex()==2){
        XFilter::Get()->Add(XTask {XTASK_ROTATE180});
    }
    else if(ui->rotateBox->currentIndex()==3){
        XFilter::Get()->Add(XTask {XTASK_ROTATE270});
    }

    // 镜像
    if(ui->flipBox->currentIndex()==1){
        XFilter::Get()->Add(XTask {XTASK_FLIPX});
    }
    else if(ui->flipBox->currentIndex()==2){
        XFilter::Get()->Add(XTask {XTASK_FLIPY});
    }
    else if(ui->flipBox->currentIndex()==3){
        XFilter::Get()->Add(XTask {XTASK_FLIPXY});
    }

    // 水印
    if(isMark){
        double x = ui->mark_x->value();
        double y = ui->mark_y->value();
        double alpha = ui->mark_alpha->value();
        double size = ui->mark_size->value();
        XFilter::Get()->Add(XTask {XTASK_MARK,{x,y,alpha,size}});
    }

    // 融合
    if(isBlend){
        double alpha = ui->blend_alpha->value();
        XFilter::Get()->Add(XTask {XTASK_BLEND,{alpha}});
    }

    // 合并
    if(isMerge){
        double h1 = XVideoThread::Get()->high;
        double h2 = XVideoThread::Get()->high2;
        int w2 = XVideoThread::Get()->width2* (h1/h2);
        XFilter::Get()->Add(XTask {XTASK_MERGE});
        ui->width->setValue(XVideoThread::Get()->width+w2);
        ui->high->setValue(h1);
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
    if(XVideoThread::Get()->StartSave(filename,ui->width->value(), ui->high->value(),isColor)){
        isExport=true;
        ui->exportButton->setText("stop Export");
    }
}

void XVideoUI::ExprotEnd(){
    isExport=false;
    ui->exportButton->setText("start Export");

    // 处理音频 
    string srcFile = XVideoThread::Get()->src1file;
    string dst = XVideoThread::Get()->DstFile;
    int ss =0;
    int t =0;
    ss = XVideoThread::Get()->totalMs * ((double)ui->leftSlider->value()/1000);
    int end = XVideoThread::Get()->totalMs * ((double)ui->rightSlider->value()/1000);
    t = end-ss;

    XAudio::Get()->ExportAu(srcFile, srcFile+".mp3",ss,t);
    string tmp = dst+".avi";
    QFile::remove(tmp.c_str());
    QFile::rename(dst.c_str(),tmp.c_str());
    XAudio::Get()->Merge(tmp, srcFile+".mp3", dst);
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

void XVideoUI::Mark(){
    isMark=false;
    QString name = QFileDialog::getOpenFileName(this,"select mark image:");
    if(name.isEmpty()){
        return;
    }
    std::string file = name.toLocal8Bit().data();
    cv::Mat mark = cv::imread(file);
    if(mark.empty()) return;
    XVideoThread::Get()->SetMark(mark);

    isMark=true;
}

void XVideoUI::Blend(){
    isBlend=false;
    isMerge=false;
    QString name = QFileDialog::getOpenFileName(this,"select video:");
    if(name.isEmpty()){
        return;
    }
    std::string file = name.toLocal8Bit().data();
    isBlend = XVideoThread::Get()->Open2(file);

} 

void XVideoUI::Merge(){
    isBlend=false;
    isMerge=false;
    QString name = QFileDialog::getOpenFileName(this,"select video:");
    if(name.isEmpty()){
        return;
    }
    std::string file = name.toLocal8Bit().data();
    isMerge = XVideoThread::Get()->Open2(file);

} 