/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-20 11:14:12
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-22 15:08:41
 * @FilePath: /Simple_geometric_expert_system/code/source/MainWindow.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <qmainwindow.h>

#include "../include/MainWindow.h"
#include "../include/Rule.h"


void test() {
    Rule r1({"三条边","任意两边之和大于第三边"},"这是三角形","测试1");
    Rule r2({"四条边","任意对边平行"},"这是平行四边形","测试2");
    Rule r3({"四条边","任意对边平行", "相邻两边为90度"},"这是矩形","测试3");


    std::cout << r1.toString() << std::endl;
    std::cout << r2.toString() << std::endl;
    std::cout << r3.toString() << std::endl;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitWindow();

    test();
}

MainWindow::~MainWindow() {
    if(!MainWidget) {
        delete MainWidget;
    }
}


void MainWindow::show() {
    this->MainWidget->show();
}


void MainWindow::InitWindow() {
    this->MainWidget = new QMainWindow();
}
