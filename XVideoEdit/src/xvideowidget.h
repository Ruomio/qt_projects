/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:41:41
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-29 21:10:49
 * @FilePath: /XVideoEdit/src/xvideowidget.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOWIDGET_H
#define XVIDEOWIDGET_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include <qwidget.h>
class XVideoWidget:public QOpenGLWidget{
    
    Q_OBJECT

public:
    XVideoWidget(QWidget *p);
    virtual ~XVideoWidget();
    void paintEvent(QPaintEvent *e);
};

#endif