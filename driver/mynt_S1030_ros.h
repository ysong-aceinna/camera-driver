/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#pragma once
// #include <stdio.h>
// #include <queue>
// #include <map>
// #include <thread>
// #include <mutex>
// #include <ros/ros.h>
// #include <cv_bridge/cv_bridge.h>
// #include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
#include "driver.h"
#include "../util/cv_painter.h"

class CMyntS1030ROSDriver : public CDriverBase
{
private:

public:
  CMyntS1030ROSDriver();
  virtual ~CMyntS1030ROSDriver();

  virtual int Init();
  virtual void Start();
  virtual void Stop();
  virtual void ThreadGetData();

  // SImgData ImageDataConvert(const api::StreamData src);
  // SImuData IMUDataConvert(const api::MotionData src);
  // SImgData ModifyImage(const cv::Mat img, const SImgData imgData);

};
