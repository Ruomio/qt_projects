/*
 * @Author: papillon 1065940593@qq.com
 * @Date: 2023-02-01 11:19:32
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-02-04 22:06:45
 * @FilePath: /XVideoEdit/src/XFilter.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "XFilter.h"
#include "XImagePro.h"
#include <opencv2/core/mat.hpp>
#include <vector>
#include <QMutex>

class CXFilter : public XFilter
{
public:
    std::vector<XTask>  tasks;

    QMutex mutex;
    
    cv::Mat Filter(cv::Mat mat1, cv::Mat mat2)
    {   
        mutex.lock();
        XImagePro p;
        p.Set(mat1, mat2);
        int size = tasks.size();
        for(int i=0;i<size;i++){
            switch (tasks[i].type) {
                case XTASK_GAIN:
                    // 亮度对比度调整
                    p.Gain(tasks[i].para[0], tasks[i].para[1]);
                    break;

                case XTASK_ROTATE90:
                    p.Rotate90();
                    break;
                case XTASK_ROTATE180:
                    p.Rotate180();
                    break;
                case XTASK_ROTATE270:
                    p.Rotate270();
                    break;

                case XTASK_FLIPX:
                    p.FlipX();
                    break;     
                case XTASK_FLIPY:
                    p.FlipY();
                    break;
                case XTASK_FLIPXY:
                    p.FlipXY();
                    break;
                case XTask_RESIZE:
                    p.Resize(tasks[i].para[0], tasks[i].para[1]);
                    break;
                case XTask_PYDOWN:
                    p.PyDown(tasks[i].para[0]);
                    break;
                case XTask_PYUP:
                    p.PyUp(tasks[i].para[0]);
                    break;
                case XTask_CLIP:
                    p.Clip(tasks[i].para[0],tasks[i].para[1],tasks[i].para[2],tasks[i].para[3]);
                    break;
                
                default: break;
            }
        }
        cv::Mat re = p.Get();
        mutex.unlock();
        return re;
    }
    void Add(XTask task)
    {
        mutex.lock();
        tasks.push_back(task);
        mutex.unlock();
    }
    void Clear()
    {
        mutex.lock();
        tasks.clear();
        mutex.unlock();
    }
    
};

XFilter::XFilter()
{
    
}

XFilter::~XFilter()
{

}

XFilter *XFilter::Get()
{
    static CXFilter cx;
    return &cx;
}