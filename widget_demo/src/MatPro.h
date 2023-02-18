/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-18 09:42:52
 * @FilePath: /widget_demo/src/MatPro.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MATPRO_H
#define MATPRO_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

#pragma once

class MatPro
{
public:

    std::vector<cv::Mat> images;
    std::vector<std::string> labels;
    
    ~MatPro();
    // 单件模式，只能通过Get获取对象
    static MatPro *Get(){
        static MatPro mp;
        return &mp;
    }

    cv::Mat  preProcess(cv::Mat mat);
    
    cv::Mat funTrain(cv::Mat mat, std::string labels);

    void detectFace(cv::Mat mat, cv::Mat afterProcess, std::string str="face");
    


protected:
    MatPro();



};

#endif