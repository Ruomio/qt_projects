/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-06 16:39:36
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 22:26:02
 * @FilePath: /XVideoEdit/src/XAudio.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XAUDIO_H
#define XAUDIO_H

#include <cstdio>
#pragma once
#include <string>

struct XTime{
    int h=0,m=0,s=0,ms=0;
    XTime(int tms){
        h=(tms/1000)/3600;
        m=(tms/1000)%3600/60;
        s=(tms/1000)%(3600*60);
        ms=tms%1000;
    }
    std::string toString(){
        char buff[16]={};
        sprintf(buff, "%d:%d:%d.%d",h,m,s,ms);
        return buff;
    }
};

class XAudio
{
public:
    static XAudio *Get();
    virtual bool ExportAu(std::string src, std::string out, int beginMs=0, int outMs=0)=0;
    virtual bool Merge(std::string src_v,std::string src_au, std::string out)=0;
    virtual ~XAudio();

protected:
    XAudio();


private:

};

#endif