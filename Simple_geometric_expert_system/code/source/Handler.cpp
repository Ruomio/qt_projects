/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-22 15:18:01
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-22 23:04:01
 * @FilePath: /Simple_geometric_expert_system/code/source/Handler.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Handler.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>


Handler::Handler() {

}

Handler::~Handler() {

}

float Handler::calculateLength(Line l) {
    return std::sqrt(std::pow((l.end.x - l.start.x),2) + std::pow((l.end.y - l.start.y),2));
}

float Handler::calculateAngle(Line l) {
    // 判断垂直情况
    if (l.end.x == l.start.x) {
        return 90.0;
    }
    return std::atan2(l.end.y - l.start.y, l.end.x - l.start.x) * 180.0 / M_PI;
}

std::vector<std::vector<cv::Point>> Handler::getContours(cv::Mat img) {
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat threshold;
    cv::threshold(gray, threshold, 127, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(threshold, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // contours
    std::vector<std::vector<cv::Point>> approx(contours.size());
    for(int i=0; i<contours.size(); i++){
        cv::approxPolyDP(contours[i], approx[i], 0.01 * cv::arcLength(contours[i], true), true);
        this->contours.push_back(approx[i]);
    }

    return this->contours;
}

// void Handler::getLines() {

// }


std::vector<ContourLine> Handler::generateLines(std::vector<cv::Point>  contour) {
    std::vector<ContourLine> contour_lines;
    for(int i=0; i<contours.size()-1; i++) {
        contour_lines.push_back(ContourLine(cv::Point(contours[i][0].x, contours[i][0].y), cv::Point(contours[i+1][0].x, contours[i+1][0].y)));
    }
    contour_lines.push_back(ContourLine(cv::Point(contours[contours.size()-1][0].x, contours[contours.size()-1][0].y), cv::Point(contours[0][0].x, contours[0][0].y)));

    return contour_lines;
}

void Handler::generateContour_dict(std::vector<ContourLine> contour_lines) {
    for(int i=0; i<contour_lines.size(); i++) {
        this->contours_dict[i] = this->generateLines(this->contours[i]);
    }
}

bool Handler::closeEnough(cv::Point x1, cv::Point x2) {

}

cv::Point Handler::averagePoint(cv::Point x1, cv::Point x2) {

}

Vector_ Handler::getVector(cv::Point x1, cv::Point x2) {

}

/* 判断锐角 */
bool Handler::isAcute(Line l1, Line l2) {

}

/* 判断钝角 */
bool Handler::isObtuse(Line l1, Line l2) {

}

/* 是否封闭 */
bool Handler::isClosure(std::vector<Line> lines) {

}



int Handler::getMeetingPoint(Line l1, Line l2) {     // 0:没有关系   1:平行  2:重合

}

bool Handler::isLengthEqual(Line l1, Line l2) {

}

bool Handler::isLengthEqual(std::vector<Line> lines) {

}

bool Handler::isParallel(Line l1, Line l2) {

}

bool Handler::isVertical(Line l1, Line l2) {

}

void Handler::factLinesClosureNumber(std::vector<Fact> facts, std::vector<Line> lines) {

}

void Handler::factLinesClosureEqual(std::vector<Fact> facts, std::vector<Line> lines) {
    
}
void Handler::factLinesClosureParallel(std::vector<Fact> facts, std::vector<Line> lines) {

}
void Handler::factAngleAcuteNumber(std::vector<Fact> facts, std::vector<Line> lines) {

}
void Handler::factAngleRightNumber(std::vector<Fact> facts, std::vector<Line> lines) {

}
void Handler::factAboutAngle(std::vector<Fact> facts, Line l1, Line l2) {

}
void Handler::factAboutlength(std::vector<Fact> facts, Line l1, Line l2) {

}
std::pair<std::vector<Fact>,std::vector<Fact>> Handler::factGenerate(std::vector<Line> lines) {

}


float Handler::getInnerProduct(Vector_ v1, Vector_ v2) {  // 向量内积

}






/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
ContourLine::ContourLine() {

}
ContourLine::ContourLine(cv::Point p1, cv::Point p2) : p1(p1), p2(p2){

}
ContourLine::~ContourLine() {

}

std::string ContourLine::toString() {
    
}