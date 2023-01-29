/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-28 20:36:56
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-29 19:56:19
 * @FilePath: /widget_demo/mainwindow.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qnamespace.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

