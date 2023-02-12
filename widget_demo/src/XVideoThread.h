/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-11 12:49:47
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-11 14:28:18
 * @FilePath: /widget_demo/src/XVideoThread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOTHREAD_H
#define XVIDEOTHREAD_H

#include <qobject.h>
#include <qtmetamacros.h>
#include <QMutex>
#include <QThread>
#pragma once

class XVideoThread:public QThread
{
    Q_OBJECT

public:
    // 单件模式，获取对象
    static XVideoThread *Get(){
        static XVideoThread vt;
        return &vt;
    }
    ~XVideoThread();

    int fps=0;
    int width=0;
    int height=0;

    bool Open(const std::string file);

protected:
    XVideoThread();
    QMutex mutex;
};

#endif