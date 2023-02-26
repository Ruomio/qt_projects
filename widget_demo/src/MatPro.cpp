/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-02-17 15:27:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-26 10:09:06
 * @FilePath: /widget_demo/src/MatPro.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MatPro.h"
#include <exception>
#include <libmodplug/stdafx.h>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/face/facerec.hpp>
#include <opencv4/opencv2/objdetect.hpp>


#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace cv;
using namespace std;

static CascadeClassifier faceCascade;
static vector<cv::Rect> faces;

MatPro::MatPro()
{
 
}

MatPro::~MatPro()
{

}



Mat  MatPro::preProcess(cv::Mat mat){
    Mat mat_gray;
    cvtColor(mat, mat_gray, COLOR_BGR2GRAY);    // 灰度图
    normalize(mat_gray, mat_gray, 0, 255, NORM_MINMAX, CV_8UC1);
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

    // model = cv::face::EigenFaceRecognizer::create();
    model = cv::face::FisherFaceRecognizer::create();
    // model = cv::face::LBPHFaceRecognizer::create();

    try {
        model->read("/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/face_train.yml");
        cout<<"模型加载完成！！！"<<endl;
        return;
    } catch (exception &e) {
        cout<<"正在训练..."<<endl;
    }
    // if(!model->empty()){
    //     model->read("/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/face_train.yml");
    //     cout<<"模型已存在！"<<endl;
    //     return;
    // }

    
    Mat src;
    string path,pattern;
    vector<cv::String> filenames,res;

    // 训练人脸数据集
    path="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/105_classes_pins_dataset";
    GetFileNames(path, filenames);
    int i=0;
    // for(auto name : filenames){
    for(i=0;i<5;i++){
        string name = filenames[i];
        // cout<<name<<endl;
        glob(name, res);
        for(int j=0; j<res.size(); j++){
            src=imread(res[j]);
            // 预处理
            cvtColor(src, src, COLOR_BGR2GRAY);
            normalize(src, src, 0, 255, NORM_MINMAX, CV_8UC1);
            equalizeHist(src, src);
            resize(src, src, Size(300,300));
            MatPro::Get()->funTrain(src, i);
        }
    }

    // pattern="/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/images/merchant/bezos_*.jpeg";
    // glob(pattern,res);
    // for(int i=0; i<res.size(); i++){
    //     src=imread(res[i]);
    //     // 预处理
    //     cvtColor(src, src, COLOR_BGR2GRAY);
    //     normalize(src, src, 0, 255, NORM_MINMAX, CV_8UC1);
    //     equalizeHist(src, src);
    //     resize(src, src, Size(300,300));
    //     MatPro::Get()->funTrain(src, 0);
    // }

    model->train(images, labels);
    cout<<"模型训练完成"<<endl;
    model->save("/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/face_train.yml");
}






void MatPro::detectFace(cv::Mat mat,cv::Mat afterProcess, int predic, double alpha_w, double alpha_h){
    
    
    
    
    string str = "not know";

    switch (predic) {
        case 1: str="Lili Reinhart";            break;
        case 2: str="Elizabeth Lail";           break;
        case 3: str="Tuppence Middleton";       break;
        case 4: str="jeff bezos";               break;
        case 5: str="Maisie Williams";          break;
        // case 6: str="Chris Evans";              break;
        // case 7: str="Morena Baccarin";          break;
        // case 8: str="Brie Larson";              break;
        // case 9: str="Shakira Isabel Mebarak";   break;
        // case 10: str="Natalie Portman";         break;    
        // case 11: str="Anne Hathaway";           break;    
        // case 12: str="Natalie Dormer";          break;    
        // case 13: str="Anthony Mackie";          break;    
        // case 14: str="Gwyneth Paltrow";         break;    
        // case 15: str="Emma Stone";              break;    
        // case 16: str="alycia dabnem carey";     break;    
        // case 17: str="Leonardo DiCaprio";       break;    
        // case 18: str="grant gustin";            break;    
        // case 19: str="Zoe Saldana";             break;    
        // case 20: str="Lindsey Morgan";          break;        
        // case 21: str="Zac Efron";               break;
        // case 22: str="Dominic Purcell";         break;
        // case 23: str="Ben Affleck";             break;
        // case 24: str="Sarah Wayne Callies";     break;
        // case 25: str="Jessica Barden";          break;
        // case 26: str="margot robbie";           break;
        // case 27: str="Mark Ruffalo";            break;
        // case 28: str="Alexandra Daddario";      break;
        // case 29: str="Amanda Crew";             break;
        // case 30: str="Hugh Jackman";            break;
        // case 31: str="Irina Shayk";             break;
        // case 32: str="Megan Fox";               break;
        // case 33: str="Eliza Taylor";            break;
        // case 34: str="Penn Badgley";            break;
        // case 35: str="Rihanna";                 break;
        // case 36: str="Katherine Langford";      break;
        // case 37: str="Lionel Messi";            break;
        // case 38: str="Jennifer Lawrence";       break;
        // case 39: str="melissa fumero";          break;
        // case 40: str="Chris Pratt";             break;
        // case 41: str="Andy Samberg";            break;
        // case 42: str="elon musk";               break;
        // case 43: str="Wentworth Miller";        break;
        // case 44: str="Jimmy Fallon";            break;
        // case 45: str="kiernen shipka";          break;
        // case 46: str="Henry Cavil";             break;
        // case 47: str="Alvaro Morte";            break;
        // case 48: str="Pedro Alonso";            break;
        // case 49: str="Johnny Depp";             break;
        // case 50: str="Taylor Swift";            break;
        // case 51: str="Tom Hardy";               break;
        // case 52: str="Selena Gomez";            break;
        // case 53: str="Morgan Freeman";          break;
        // case 54: str="Chris Hemsworth";         break;
        // case 55: str="Millie Bobby Brown";      break;
        // case 56: str="Emma Watson";             break;
        // case 57: str="Rami Malek";              break;
        // case 58: str="Maria Pedraza";           break;
        // case 59: str="Robert De Niro";          break;
        // case 60: str="barack obama";            break;
        // case 61: str="Brian J. Smith";                        break;
        // case 62: str="tom ellis";                     break;
        // case 63: str="Zendaya";                       break;
        // case 64: str="Sophie Turner";                     break;
        // case 65: str="Josh Radnor";                       break;
        // case 66: str="Tom Hiddleston";                        break;
        // case 67: str="Inbar Lavi";                        break;
        // case 68: str="Mark Zuckerberg";                       break;
        // case 69: str="ellen page";                        break;
        // case 70: str="barbara palvin";                        break;
        // case 71: str="Jeremy Renner";                     break;
        // case 72: str="scarlett johansson";                        break;
        // case 73: str="Nadia Hilker";                      break;
        // case 74: str="Tom Cruise";                        break;
        // case 75: str="Neil Patrick Harris";                       break;
        // case 76: str="Ursula Corbero";                        break;
        // case 77: str="Jake Mcdorman";                     break;
        // case 78: str="Cristiano Ronaldo";                     break;
        // case 79: str="Madelaine Petsch";                      break;
        // case 80: str="Richard Harmon";                        break;
        // case 81: str="Marie Avgeropoulos";                        break;
        // case 82: str="Bill Gates";                        break;
        // case 83: str="amber heard";                       break;
        // case 84: str="gal gadot";                     break;
        // case 85: str="Emilia Clarke";                     break;
        // case 86: str="Alex Lawther";                      break;
        // case 87: str="Bobby Morley";                      break;
        // case 88: str="Christian Bale";                        break;
        // case 89: str="Krysten Ritter";                        break;
        // case 90: str="Katharine Mcphee";                     break;
        // case 91: str="Miley Cyrus";                      break;
        // case 92: str="Brenton Thwaites";                     break;
        // case 93: str="Robert Downey Jr";                     break;
        // case 94: str="camila mendes";                    break;
        // case 95: str="Stephen Amell";                    break;
        // case 96: str="Keanu Reeves";                     break;
        // case 97: str="Logan Lerman";                     break;
        // case 98: str="Tom Holland";                      break;
        // case 99: str="elizabeth olsen";                      break;
        // case 100: str="Jason Momoa";               break;
        // case 101: str="Rebecca Ferguson";              break;
        // case 102: str="Avril Lavigne";             break;
        // case 103: str="Danielle Panabaker";                break;
        // case 104: str="Adriana Lima";              break;
        // case 105: str="Dwayne Johnson";                break;
       
        default: break;

    }
    
    // 加载特征文件
    // CascadeClassifier faceCascade;
    string haar_face_datapath = "/home/papillon/Documents/All_Code/Qt_projeces/widget_demo/trains/haarcascade_frontalface_alt2.xml";
    if(faceCascade.empty()){
        cout << "人脸检测级联分类器为空！！" << endl;
        if (!faceCascade.load(haar_face_datapath)){
            cout << "人脸检测级联分类器没找到！！" << endl;
            return;
        }
    }
    
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
			// cout << faces[i] << endl;
		}
	}
}


void MatPro::GetFileNames(std::string path, std::vector<std::string> &filenames){
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0){
            filenames.push_back(path + "/" + ptr->d_name);
    }
    }
    closedir(pDir);
    delete [] ptr;
}