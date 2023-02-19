/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-19 20:28:57
 * @FilePath: /widget_demo/src/MatPro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MatPro.h"
#include <libmodplug/stdafx.h>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/face/facerec.hpp>
#include <opencv4/opencv2/objdetect.hpp>

using namespace cv;
using namespace std;




MatPro::MatPro()
{
 
}

MatPro::~MatPro()
{

}



Mat  MatPro::preProcess(cv::Mat mat){
    Mat mat_gray;
    cvtColor(mat, mat_gray, COLOR_BGR2GRAY);    // 灰度图
    equalizeHist(mat_gray, mat_gray);   // 直方图均值化
    // pyrDown(mat_gray, mat_gray);    // 高斯模糊，向下采样，像素量为原来 1/4
    return mat_gray;
}

cv::Mat MatPro::funTrain(cv::Mat src, int lable){
    images.push_back(src);
    labels.push_back(lable);
    return src;
}

void MatPro::faceTrain(){
    // 加载特征文件
    CascadeClassifier faceCascade;
    string haar_face_datapath = "/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/haarcascade_frontalface_alt2.xml";
    if (!faceCascade.load(haar_face_datapath)){
		cout << "人脸检测级联分类器没找到！！" << endl;
		return;
	}
    vector<Rect> faces;
	



    model = cv::face::FisherFaceRecognizer::create();
    // model = cv::face::EigenFaceRecognizer::create();

    // model->read("/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/face_train.model");
    // if(!model->empty()){
    //     cout<<"模型已存在！"<<endl;
    //     return;
    // }

    
    Mat src;
    // 遍历图片 lable=0
    string pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/bezos_*.jpeg";
    vector<cv::String> res;
    glob(pattern, res);
    cout<<"bezos"<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        src=imread(res[i]);
        // 预处理
        cvtColor(src, src, COLOR_BGR2GRAY);
        equalizeHist(src, src);
        // 裁切人脸区域
        faceCascade.detectMultiScale(src, faces, 1.2, 5, 0, Size(30, 30));
        // 检测到多张人脸舍去
        if(faces.size()!=1){
            continue;
        }
        src=src(Rect(faces[0].x, faces[0].y, faces[0].width, faces[0].height));
        resize(src, src, Size(300,300));
        MatPro::Get()->funTrain(src, 0);
    }
    // 遍历图片 lable=1
    pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/bill_*.jpeg";
    glob(pattern, res);
    cout<<"bill"<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        src=imread(res[i]);
        cvtColor(src, src, COLOR_BGR2GRAY);
        equalizeHist(src, src);
        // 裁切人脸区域
        faceCascade.detectMultiScale(src, faces, 1.2, 5, 0, Size(30, 30));
        // 检测到多张人脸舍去
        if(faces.size()!=1){
            continue;
        }
        src=src(Rect(faces[0].x, faces[0].y, faces[0].width, faces[0].height));
        resize(src, src, Size(300,300));
        MatPro::Get()->funTrain(src, 1);
    }
    // 遍历图片 lable=2
    pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/jack_ma_*.jpeg";
    glob(pattern, res);
    cout<<"jack_ma"<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        src=imread(res[i]);
        cvtColor(src, src, COLOR_BGR2GRAY);
        equalizeHist(src, src);
        // 裁切人脸区域
        faceCascade.detectMultiScale(src, faces, 1.2, 5, 0, Size(30, 30));
        // 检测到多张人脸舍去
        if(faces.size()!=1){
            continue;
        }
        src=src(Rect(faces[0].x, faces[0].y, faces[0].width, faces[0].height));
        resize(src, src, Size(300,300));
        MatPro::Get()->funTrain(src, 2);
    }
    // 遍历图片 lable=3
    pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/mask_*.jpeg";
    glob(pattern, res);
    cout<<"mask"<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        src=imread(res[i]);
        cvtColor(src, src, COLOR_BGR2GRAY);
        equalizeHist(src, src);
        // 裁切人脸区域
        faceCascade.detectMultiScale(src, faces, 1.2, 5, 0, Size(30, 30));
        // 检测到多张人脸舍去
        if(faces.size()!=1){
            continue;
        }
        src=src(Rect(faces[0].x, faces[0].y, faces[0].width, faces[0].height));
        resize(src, src, Size(300,300));
        MatPro::Get()->funTrain(src, 3);
    }
    // 遍历图片 lable=4
    pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/ppz_*.png";
    glob(pattern, res);
    cout<<"ppz"<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        src=imread(res[i]);
        cvtColor(src, src, COLOR_BGR2GRAY);
        equalizeHist(src, src);
        // 裁切人脸区域
        faceCascade.detectMultiScale(src, faces, 1.2, 5, 0, Size(30, 30));
        // 检测到多张人脸舍去
        if(faces.size()!=1){
            continue;
        }
        src=src(Rect(faces[0].x, faces[0].y, faces[0].width, faces[0].height));
        resize(src, src, Size(300,300));
        MatPro::Get()->funTrain(src, 4);
    }
    
    model->train(images, labels);
    cout<<"模型训练完成"<<endl;
    model->save("/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/face_train.model");
}

void MatPro::detectFace(cv::Mat mat,cv::Mat afterProcess, int predic, double alpha_w, double alpha_h){
    // 加载特征文件
    CascadeClassifier faceCascade;
    string haar_face_datapath = "/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/haarcascade_frontalface_alt2.xml";
    if (!faceCascade.load(haar_face_datapath)){
		cout << "人脸检测级联分类器没找到！！" << endl;
		return;
	}
    
    string str = "not know";

    switch (predic) {
        case 0:  str="bezos";   break;
        case 1:  str="bill";   break;
        case 2:  str="jack_ma";   break;
        case 3:  str="mask";   break;
        case 4:  str="ppz";   break;
       
        default: break;

    }
    

    vector<Rect> faces;
	faceCascade.detectMultiScale(afterProcess, faces, 1.2, 5, 0, Size(30, 30));
    for (auto b : faces) {
		cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (width,height):(" << b.width << "," << b.height << ")" << "this is :"<<str<< endl;
        
	}
    if (faces.size()>0) {
		for (size_t i = 0; i<faces.size(); i++) {
			// putText(img, "face", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));
			cv::putText(mat, str, Point(faces[i].x *alpha_w, faces[i].y *alpha_h - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));
			
            // 图像预处理时尺寸改变, 这里在原图画矩形要恢复
			cv::rectangle(mat, Point(faces[i].x *alpha_w, faces[i].y *alpha_h), Point(faces[i].x *alpha_w + faces[i].width*alpha_w, faces[i].y *alpha_h + faces[i].height*alpha_h), Scalar(0, 0, 255), 1, 8);
			cout << faces[i] << endl;
		}
	}
}

