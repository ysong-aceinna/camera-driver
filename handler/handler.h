/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#pragma once
#include <iostream>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include "../driver/struct.h"
#include <glog/logging.h>
#include "../util/macro.h"

using namespace std;

class CHandler
{
private:

public:
    CHandler();
    ~CHandler();
    
    void UpdateLeftImage (SImgData img);
    void UpdateRightImage(SImgData img);
    void UpdateIMU(SImuData& imu);
};