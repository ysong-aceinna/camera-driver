/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#include "mynt_S1030_ros.h"


CMyntS1030ROSDriver::CMyntS1030ROSDriver()
{
  cout << "CMyntS1030ROSDriver:CMyntS1030ROSDriver()" << endl;
}

CMyntS1030ROSDriver::~CMyntS1030ROSDriver()
{
  cout << "CMyntS1030ROSDriver:~CMyntS1030ROSDriver()" << endl;
}

int CMyntS1030ROSDriver::Init()
{

  return 0;
}

void CMyntS1030ROSDriver::Start()
{
  LOG(INFO) << "CMyntS1030ROSDriver::Start()";
}

void CMyntS1030ROSDriver::Stop()
{
  LOG(INFO) << "CMyntS1030ROSDriver::Stop()";
}

void CMyntS1030ROSDriver::ThreadGetData()
{
  LOG(INFO) << "CMyntS1030ROSDriver::ThreadGetData()";
}

// SImgData CMyntS1030ROSDriver::ImageDataConvert(const api::StreamData src)
// {
//   SImgData dst;
//   return dst;
// }

// SImuData CMyntS1030ROSDriver::IMUDataConvert(const api::MotionData src)
// {
//   SImuData dst;
//   return dst;
// }

// SImgData CMyntS1030ROSDriver::ModifyImage(const cv::Mat img, const SImgData imgData)
// {
//   SImgData new_image(imgData);
//   img.copyTo(new_image.frame);
//   return new_image;
// }
