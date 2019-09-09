
#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../driver/struct.h"
using namespace std;

class CHandler
{
private:
    /* data */
public:
    CHandler(/* args */);
    ~CHandler();
    
    void UpdateLeftImage (cv::Mat img);
    void UpdateRightImage(cv::Mat img);
    void UpdateIMU(SImuData& imu);
};