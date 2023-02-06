/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 08:37:25
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-06 16:20:29
 * @FilePath: /XVideoEdit/src/XImagePro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XImagePro.h"
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

XImagePro::XImagePro()
{

}

XImagePro::~XImagePro()
{

}

void XImagePro::Set(cv::Mat mat1, cv::Mat mat2, cv::Mat mark)
{
    this->src1=mat1;
    this->src2=mat2;
    this->mark=mark;
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
    dst.convertTo(dst, -1, contrast, bright);
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

void XImagePro::Gray(){
    if(dst.empty()) return;
    cv::cvtColor(dst, dst, cv::COLOR_BGR2GRAY);
}
void XImagePro::Binary(){
    if(dst.empty()) return;
    cv::threshold(dst,dst,100,255,cv::THRESH_BINARY);
}

void XImagePro::Mark(int x, int y, double alpha,double size){
    if(dst.empty()) return;
    if(mark.empty()) return;
    // 改变水印大小
    int w = size*mark.cols;
    int h = size*mark.rows;
    cv::resize(mark, mark, cv::Size(w,h));
    cv::Mat rol = dst(cv::Rect(x,y,mark.cols, mark.rows));
    cv::addWeighted(mark, alpha, rol, 1-alpha, 0, rol);
}

void XImagePro::Blend(double alpha){
if(dst.empty()) return;
if(src2.empty()) return;
if(src2.size()!=dst.size()){
    cv::resize(src2, src2, dst.size());
}
cv::addWeighted(src2, alpha, dst, 1-alpha, 0, dst);
}

void XImagePro::Merge(){
    if(dst.empty()) return;
    if(src2.empty()) return;
    if(src2.size()!=dst.size()){
        cv::resize(src2, src2, cv::Size((int)(src2.cols *  (double)dst.rows/src2.rows), dst.rows));
    }
    int width = dst.cols + src2.cols;
    int high = dst.rows;
    // 只能以src1为基准
    dst = cv::Mat(cv::Size(width,high),dst.type());
    cv::Mat r1 = dst(cv::Rect(0,0,src1.cols,high));
    cv::Mat r2 = dst(cv::Rect(src1.cols,0,src2.cols,high));
    src1.copyTo(r1);
    src2.copyTo(r2);

}