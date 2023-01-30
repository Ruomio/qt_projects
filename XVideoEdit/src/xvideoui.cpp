/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 08:35:25
 * @FilePath: /XVideoEdit/src/xvideoui.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideoui.h"
#include "./ui_xvideoui.h"
#include "xvideothread.h"
#include <QFileDialog>
#include <qfiledialog.h>
#include <QMessageBox>
#include <string>
#include <iostream>
using namespace std;

XVideoUI::XVideoUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XVideoUI)
{
    ui->setupUi(this);
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