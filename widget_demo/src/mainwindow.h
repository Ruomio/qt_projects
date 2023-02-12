/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-11 10:39:30
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-11 16:28:27
 * @FilePath: /widget_demo/src/mainwindow.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtmetamacros.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void Open();

};
#endif // MAINWINDOW_H
