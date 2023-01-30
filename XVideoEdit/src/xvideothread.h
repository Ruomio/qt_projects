/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-30 07:51:28
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-01-30 08:31:32
 * @FilePath: /XVideoEdit/src/xvideothread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOTHREAD_H
#define XVIDEOTHREAD_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QThread>

class XVideoThread:QThread
{ 
public:
    
    ~XVideoThread();
    static XVideoThread*Get(){
        static XVideoThread vt;
        return &vt;
    }
    bool Open(const std::string file);
    // 线程入口
    void run();

protected:
    // 限定不能从外部生成对象
    XVideoThread();
};

#endif // XVIDEOTHREAD_H
