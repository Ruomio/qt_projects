/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-01-29 20:26:21
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 19:56:05
 * @FilePath: /XVideoEdit/src/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xvideoui.h"
// #include "XAudio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XVideoUI w;
    w.show();

    // XAudio::Get()->ExportAu("01.mp4", "01_out.mp3");
    // XAudio::Get()->Merge("01_out.mp4", "01_out.mp3", "01_vAa.avi");
    return a.exec();
}
