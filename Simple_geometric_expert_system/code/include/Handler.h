/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-22 15:17:54
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-22 23:03:07
 * @FilePath: /Simple_geometric_expert_system/code/include/Handler.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __HANDLER_H__
#define __HANDLER_H__

#include <iostream>
#include <cmath>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <vector>


#define close_threshold  5      
#define equal_threshold  5
#define parallel_threshold  5
#define vertical_threshold  5


// struct Point {
//     float x;
//     float y;
// };

struct Line {
    cv::Point start;
    cv::Point end;
    float angle;
};

struct Vector_ {
    float x;
    float y;
    bool direction;     // 0:反向   1:正向
};

class Fact;
class ContourLine;

class Handler {
public:
    Handler();
    ~Handler();

    float calculateLength(Line l);
    float calculateAngle(Line l);

    std::vector<std::vector<cv::Point>> getContours(cv::Mat img);

    // void getLines();

    std::vector<ContourLine> generateLines(std::vector<cv::Point>  get_contours);

    void generateContour_dict(std::vector<ContourLine> contour_lines);

    bool closeEnough(cv::Point x1, cv::Point x2);

    cv::Point averagePoint(cv::Point x1, cv::Point x2);

    Vector_ getVector(cv::Point x1, cv::Point x2);

    /* 判断锐角 */
    bool isAcute(Line l1, Line l2);

    /* 判断钝角 */
    bool isObtuse(Line l1, Line l2);

    /* 是否封闭 */
    bool isClosure(std::vector<Line> lines);



    int getMeetingPoint(Line l1, Line l2);      // 0:没有关系   1:平行  2:重合

    bool isLengthEqual(Line l1, Line l2);

    bool isLengthEqual(std::vector<Line> lines);
    
    bool isParallel(Line l1, Line l2);

    bool isVertical(Line l1, Line l2);
    
    void factLinesClosureNumber(std::vector<Fact> facts, std::vector<Line> lines);
    void factLinesClosureEqual(std::vector<Fact> facts, std::vector<Line> lines);
    void factLinesClosureParallel(std::vector<Fact> facts, std::vector<Line> lines);
    void factAngleAcuteNumber(std::vector<Fact> facts, std::vector<Line> lines);
    void factAngleRightNumber(std::vector<Fact> facts, std::vector<Line> lines);
    void factAboutAngle(std::vector<Fact> facts, Line l1, Line l2);
    void factAboutlength(std::vector<Fact> facts, Line l1, Line l2);
    std::pair<std::vector<Fact>,std::vector<Fact>> factGenerate(std::vector<Line> lines);


    float getInnerProduct(Vector_ v1, Vector_ v2);  // 向量内积

private:
    // cv::Mat src;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<ContourLine> contour_lines;     // aka contours_dict
    std::vector<std::vector<ContourLine>>  contours_dict;
    std::vector<Fact> facts;
};

class Fact {
public:
    Fact();
    Fact(std::string fact);
    Fact(std::string fact, std::vector<std::string> about);
    ~Fact();
    
    std::string toString();

private:
    std::string fact;
    std::vector<std::string> about;

};

class ContourLine {
public:
    ContourLine();
    ContourLine(cv::Point p1, cv::Point p2);
    ~ContourLine();

    std::string toString();

private:
    cv::Point p1;
    cv::Point p2;
    float length;
    float angle;
};

#endif