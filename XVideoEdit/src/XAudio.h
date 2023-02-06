/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-06 16:39:36
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 17:09:25
 * @FilePath: /XVideoEdit/src/XAudio.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XAUDIO_H
#define XAUDIO_H

#pragma once
#include <string>

class XAudio
{
public:
    static XAudio *Get();
    virtual bool ExportAu(std::string src, std::string out)=0;
    virtual bool Merge(std::string src_v,std::string src_au, std::string out)=0;
    virtual ~XAudio();

protected:
    XAudio();


private:

};

#endif