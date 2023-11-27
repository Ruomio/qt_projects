/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-20 11:14:12
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-27 15:55:52
 * @FilePath: /Simple_geometric_expert_system/code/source/MainWindow.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <qmainwindow.h>

#include "../include/MainWindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitWindow();



}

MainWindow::~MainWindow() {
    if(!m_frame) {
        delete m_frame;
    }
}


void MainWindow::show() {
    this->m_frame->ShowWindow();
}


void MainWindow::InitWindow() {
    this->m_frame = new Frame(this);
}
