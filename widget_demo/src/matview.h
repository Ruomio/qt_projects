/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 10:51:46
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-11 11:03:23
 * @FilePath: /widget_demo/matview.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MATVIEW_H
#define MATVIEW_H

#include <QtOpenGLWidgets/QOpenGLWidget>
// #include <qwidget.h>


class MatView:public QOpenGLWidget
{
    
    Q_OBJECT

public:
    MatView(QWidget *p);
    ~MatView();
    void paintEvent(QPaintEvent *e);

protected:
    QImage img;
};

#endif // MATVIEW_H
