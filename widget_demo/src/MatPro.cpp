/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-19 15:35:26
 * @FilePath: /widget_demo/src/MatPro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MatPro.h"
#include <libmodplug/stdafx.h>
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
    pyrDown(mat_gray, mat_gray);    // 高斯模糊，向下采样，像素量为原来 1/4
    return mat_gray;
}

cv::Mat MatPro::funTrain(cv::Mat src, int lable){
    images.push_back(src);
    labels.push_back(lable);
    return src;
}

void MatPro::faceTrain(){

    Mat src=imread("../trains/images/cjm.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 0);
    src=imread("../trains/images/dgy.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 1);
    src=imread("../trains/images/fcy.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 2);
    src=imread("../trains/images/fzs.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 3);
    src=imread("../trains/images/fzw.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 4);
    src=imread("../trains/images/ht.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 5);
    src=imread("../trains/images/jcy.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 6);
    src=imread("../trains/images/lml.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 7);
    src=imread("../trains/images/py.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 8);
    src=imread("../trains/images/qyy.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 9);
    src=imread("../trains/images/tsl.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 10);
    src=imread("../trains/images/xj.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 11);
    src=imread("../trains/images/yjf.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 12);
    src=imread("../trains/images/zbp.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 13);
    src=imread("../trains/images/zdx.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 14);
    src=imread("../trains/images/zk.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 15);
    src=imread("../trains/images/zl.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 16);
    src=imread("../trains/images/zwl.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 17);
    src=imread("../trains/images/zxq.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 18);
    src=imread("../trains/images/zyp.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 19);
    src=imread("../trains/images/zzl.png",IMREAD_GRAYSCALE);
    resize(src, src, Size(300,300));
    MatPro::Get()->funTrain(src, 20);

    model = cv::face::FisherFaceRecognizer::create();
    model->train(images, labels);
    
}

void MatPro::detectFace(cv::Mat mat,cv::Mat afterProcess, int predic){
    // 加载特征文件
    CascadeClassifier faceCascade;
    string haar_face_datapath = "../trains/haarcascade_frontalface_alt2.xml";
    if (!faceCascade.load(haar_face_datapath)){
		cout << "人脸检测级联分类器没找到！！" << endl;
		return;
	}
    
    string str = "face";

    switch (predic) {
        case 0:  str="cjm";   break;
        case 1:  str="dgy";   break;
        case 2:  str="fcy";   break;
        case 3:  str="fzs";   break;
        case 4:  str="fzw";   break;
        case 5:  str="ht";   break;
        case 6:  str="jcy";   break;
        case 7:  str="lml";   break;
        case 8:  str="py";   break;
        case 9:  str="qyy";   break;
        case 10: str="tsl";    break;
        case 11: str="xj";    break;
        case 12: str="yjf";    break;
        case 13: str="zbp";    break;
        case 14: str="zdx";    break;
        case 15: str="zk";    break;
        case 16: str="zl";    break;
        case 17: str="zwl";    break;
        case 18: str="zxq";    break;
        case 19: str="zyp";    break;
        case 20: str="zzl";    break;

    }
    

    vector<Rect> faces;
	faceCascade.detectMultiScale(afterProcess, faces, 1.2, 5, 0, Size(30, 30));
    for (auto b : faces) {
		cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (width,height):(" << b.width << "," << b.height << ")" << endl;
	}
    if (faces.size()>0) {
		for (size_t i = 0; i<faces.size(); i++) {
			// putText(img, "face", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));
			cv::putText(mat, str, Point(faces[i].x *2, faces[i].y *2 - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));
			
            // 图像预处理时尺寸缩小了1/2, 这里在原图画矩形要乘2
			cv::rectangle(mat, Point(faces[i].x *2, faces[i].y *2), Point(faces[i].x *2 + faces[i].width*2, faces[i].y *2 + faces[i].height*2), Scalar(0, 0, 255), 1, 8);
			cout << faces[i] << endl;
		}
	}
}

