/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../driver/struct.h"
#include "mynteye/logger.h"

using namespace std;

class CHandler
{
private:
    /* data */
public:
    CHandler();
    ~CHandler();
    
    void UpdateLeftImage (cv::Mat img);
    void UpdateRightImage(cv::Mat img);
    void UpdateIMU(SImuData& imu);
};