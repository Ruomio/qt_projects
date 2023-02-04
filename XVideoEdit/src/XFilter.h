/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 11:19:32
 * @LastEditors: Ruomio 1065940593@qq.com
 * @LastEditTime: 2023-02-04 12:05:12
 * @FilePath: /XVideoEdit/src/XFilter.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XFILTER_H
#define XFILTER_H

#pragma once

#include <opencv4/opencv2/core.hpp>
#include <vector>

enum XTaskType{
    XTASK_NONE,
    XTASK_GAIN,     // 亮度对比度
    XTASK_ROTATE90,
    XTASK_ROTATE180,
    XTASK_ROTATE270,
    
};

struct XTask{
    XTaskType type;
    std::vector<double> para;
};

class XFilter
{
public:
    // 暴露给xvideo.ui的接口
    virtual cv::Mat Filter(cv::Mat mat1, cv::Mat mat2) = 0;
    virtual void Add(XTask task) = 0;
    virtual void Clear() = 0;
    static XFilter *Get();
    virtual ~XFilter();
protected:
    XFilter();

private:

};

#endif