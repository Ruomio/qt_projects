/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 08:37:25
 * @LastEditors: papillon 1065940593@qq.com
 * @LastEditTime: 2023-02-02 13:20:16
 * @FilePath: /XVideoEdit/src/XImagePro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XImagePro.h"

XImagePro::XImagePro()
{

}

XImagePro::~XImagePro()
{

}

void XImagePro::Set(cv::Mat mat1, cv::Mat mat2)
{
    this->src1=mat1;
    this->src2=mat2;
    this->src1.copyTo(dst);
}

cv::Mat XImagePro::Get(){
    return dst;
}

/**
 * @description: 调整亮度和对比度
 * @param {double} bright   亮度
 * @param {double} contrast 对比度
 * @return {*}
 */
void XImagePro::Gain(double bright, double contrast){
    if(dst.empty()) return;
    dst.convertTo(dst, -1, bright, contrast);
}
