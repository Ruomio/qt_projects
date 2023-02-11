/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 21:10:51
 * @FilePath: /XVideoEdit/src/xvideoui.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XVIDEOUI_H
#define XVIDEOUI_H

#include <QWidget>
#include <qcoreevent.h>
#include <QTimerEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class XVideoUI; }
QT_END_NAMESPACE

class XVideoUI : public QWidget
{
    
    Q_OBJECT

public:
    XVideoUI(QWidget *parent = nullptr);
    ~XVideoUI();
public slots:
    void Open();
    void timerEvent(QTimerEvent *e);
    void SliderPress();
    void SliderRelease();
    // 滑动条
    void SetPos(int pos);
    void Left(int pos);
    void Right(int pos);
    void Set();
    void Export();
    // 导出完成
    void ExprotEnd();

    void Play();
    void Pause(); 

    void Mark();

    void Blend();
    
    void Merge();

private:
    Ui::XVideoUI *ui;
};
#endif // XVIDEOUI_H
