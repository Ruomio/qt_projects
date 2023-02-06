/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 08:37:25
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-05 17:37:51
 * @FilePath: /XVideoEdit/src/XImagePro.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef XIMAGEPRO_H
#define XIMAGEPRO_H

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


#pragma once

class XImagePro
{
public:
    // 设置原图，会清理处理的结果
    void Set(cv::Mat mat1, cv::Mat mat2, cv::Mat mark); 
    // 获取处理后结果
    cv::Mat Get();
    // 设置亮度和对比度
    void Gain(double bright, double contrast);
    XImagePro();
    ~XImagePro();
    // 旋转
    void Rotate90();
    void Rotate180();
    void Rotate270();
    // 图像镜像
    void FlipX();
    void FlipY();
    void FlipXY();
    // 图像尺寸
    void Resize(int width, int high);
    // 高斯金字塔，拉普拉斯金字塔
    void PyDown(int count);
    void PyUp(int count);
    //画面裁剪
    void Clip(int x, int y, int width, int high);
    //颜色转换
    void Gray();
    void Binary();
    // 水印
    void Mark(int x, int y, double alpha,double size);
    // 融合
    void Blend(double alpha);
    // 合并
    void Merge();

private:
    // origin img
    cv::Mat src1,src2;
    // dst img
    cv::Mat dst;
    // 水印
    cv::Mat mark;
};

#endif