/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-06 16:39:36
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 22:28:48
 * @FilePath: /XVideoEdit/src/XAudio.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XAudio.h"
#include <string>
#include <iostream>
#include <QMutex>

using namespace std;
class CXAudio:public XAudio{
public:
    QMutex mutex;
    bool ExportAu(std::string src, std::string out, int beginMs, int outMs){
        // ffmpeg -i src.mp4 -i -ss %h:%m:%m.%ms -t %h:%m:%m.%ms  -vn -y out.mp3
        std::string cmd = "ffmpeg ";
        cmd += "-i ";
        cmd += src;
        cmd += " ";
        if(beginMs>0){
            cmd+=" -ss "+XTime(beginMs).toString();
        }
        if(outMs>0){
            cmd+=" -t "+XTime(outMs).toString();
        }
        cmd += " -vn -y ";
        cmd += out;
        cout<<cmd<<endl;
        mutex.lock();
        system(cmd.c_str());
        mutex.unlock();
        return true;
    }
    virtual bool Merge(std::string src_v,std::string src_au, std::string out){
        // ffmpeg -i test.mp4 -i test.mp3 -c copy out.mp4
        string cmd = "ffmpeg";
        cmd += " -i ";
        cmd += src_v;
        cmd += " -i ";
        cmd += src_au;
        cmd += " -c copy ";
        cmd += out;
        cout<<cmd<<endl;
        mutex.lock();
        system(cmd.c_str());
        mutex.unlock();
        return true;
    }
};

XAudio::XAudio()
{

}

XAudio::~XAudio()
{

}

XAudio *XAudio::Get(){
    static CXAudio ca;
    return &ca;
}