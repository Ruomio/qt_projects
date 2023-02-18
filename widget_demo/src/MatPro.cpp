/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-18 14:22:16
 * @FilePath: /widget_demo/src/MatPro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MatPro.h"
#include <opencv2/core/types.hpp>

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

cv::Mat MatPro::funTrain(cv::Mat src, string lable){
    images.push_back(src);
    labels.push_back(lable);
    return src;
}

void MatPro::detectFace(cv::Mat mat,cv::Mat afterProcess, std::string str){
     // 加载特征文件
    CascadeClassifier faceCascade;
    string haar_face_datapath = "../trains/haarcascade_frontalface_alt2.xml";
    if (!faceCascade.load(haar_face_datapath)){
		cout << "人脸检测级联分类器没找到！！" << endl;
		return;
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

