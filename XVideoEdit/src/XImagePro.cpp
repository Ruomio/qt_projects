/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 08:37:25
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-04 22:41:45
 * @FilePath: /XVideoEdit/src/XImagePro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XImagePro.h"
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>

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

void XImagePro::Rotate90(){
    if(dst.empty()) return;
    cv::rotate(dst,dst,cv::ROTATE_90_CLOCKWISE);
}
void XImagePro::Rotate180(){
    if(dst.empty()) return;
    cv::rotate(dst,dst,cv::ROTATE_180);
}
void XImagePro::Rotate270(){
    if(dst.empty()) return;
    cv::rotate(dst,dst,cv::ROTATE_90_COUNTERCLOCKWISE);
}


void XImagePro::FlipX(){
    if(dst.empty()) return;
    // 左右镜像
    flip(dst,dst,0);
}
void XImagePro::FlipY(){
    if(dst.empty()) return;
    // 上下镜像
    flip(dst,dst,1);
}
void XImagePro::FlipXY(){
    if(dst.empty()) return;
    flip(dst,dst,-1);
}

void XImagePro::Resize(int width, int high){
    if(dst.empty()) return;
    cv::resize(dst,dst, cv::Size(width,high));
}

void XImagePro::PyDown(int count){
    if(dst.empty()) return;
    for(int i=0;i<count; i++){
        cv::pyrDown(dst, dst);
    }
}
void XImagePro::PyUp(int count){
    if(dst.empty()) return;
    for(int i=0;i<count; i++){
        cv::pyrUp(dst, dst);
    }
}

void XImagePro::Clip(int x, int y, int width, int high){
    if(dst.empty()) return;
    if(x<0 || y<0 || width<=0 || high<=0) return;
    if(x>dst.cols || y>dst.rows) return;
    dst = dst(cv::Rect(x,y,width,high));

}