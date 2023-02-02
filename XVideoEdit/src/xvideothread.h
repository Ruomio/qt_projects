/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:28
 * @LastEditors: Ruomio 1065940593@qq.com
 * @LastEditTime: 2023-02-02 22:41:11
 * @FilePath: /XVideoEdit/src/xvideothread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOTHREAD_H
#define XVIDEOTHREAD_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <opencv4/opencv2/core.hpp>
#include <qthread.h>
#include <QMutex>
#include <qmutex.h>

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
    bool Open(const std::string file);
    // 线程入口
    void run();
    // 帧率
    int fps=0;
    //当前位置
    double GetPos();

    /**
     * @description:  跳转视频 ，一般用时间跳转而不用帧， 多个视频帧率不一样的情况
     * @param {int} frame 帧位置
     * @return {*}
     */    
    bool Seek(int frame);
    // 时间位置
    bool Seek(double pos);
    // 开始导出视频
    bool StartSave(const std::string filename, int width=0, int height=0);
    void StopSave();
    

signals:
    void ViewImage1(cv::Mat mat);
    
    void ViewDst(cv::Mat mat);

    void SaveEnd();



protected:
    // 限定不能从外部生成对象
    XVideoThread();
    QMutex mutex;
    bool isWrite=false;
};

#endif // XVIDEOTHREAD_H
