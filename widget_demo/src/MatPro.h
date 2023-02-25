/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-24 16:57:36
 * @FilePath: /widget_demo/src/MatPro.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MATPRO_H
#define MATPRO_H

#include <opencv4/opencv2/face/facerec.hpp>
#include <opencv4/opencv2/objdetect/face.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/face.hpp>
#include <libmodplug/stdafx.h>
#include <iostream>


#pragma once

class MatPro
{
public:

    std::vector<cv::Mat> images;
    std::vector<int> labels;
    
    cv::Ptr<cv::face::FaceRecognizer> model;

    // cv::CascadeClassifier faceCascade;

    // std::vector<cv::Rect> faces;

    
    ~MatPro();
    // 单件模式，只能通过Get获取对象
    static MatPro *Get(){
        static MatPro mp;
        return &mp;
    }

    cv::Mat  preProcess(cv::Mat mat);
    
    cv::Mat funTrain(cv::Mat mat, int label);

    void faceTrain();

    void detectFace(cv::Mat mat, cv::Mat afterProcess, int predic=-1, double alpha_w=1, double alpha_h=1);

    void GetFileNames(std::string path,std::vector<std::string>& filenames);
    

protected:
    MatPro();



};

#endif