/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:28
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 10:04:13
 * @FilePath: /XVideoEdit/src/xvideothread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOTHREAD_H
#define XVIDEOTHREAD_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <opencv4/opencv2/core.hpp>
#include <qthread.h>
#include <QMutex>

class XVideoThread:public QThread
{ 

    Q_OBJECT

public:
    // 单件模式，获取对象
    static XVideoThread*Get(){
        static XVideoThread vt;
        return &vt;
    }
    ~XVideoThread();
    bool Open(const std::string file);
    // 线程入口
    void run();
    // 帧率
    int fps=0;
    //当前位置
    double GetPos();


signals:
    void ViewImage1(cv::Mat mat);


protected:
    // 限定不能从外部生成对象
    XVideoThread();
    QMutex mutex;
};

#endif // XVIDEOTHREAD_H
