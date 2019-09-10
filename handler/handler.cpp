/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#include"handler.h"

CHandler::CHandler(/* args */)
{
}

CHandler::~CHandler()
{
}

void CHandler::UpdateLeftImage(SImgData img)
{
    cv::imshow("Left", img.frame);
    cv::waitKey(1);
    LOG(INFO) << "Left frame_id: " << img.frame_id << "  ,Left time: " << img.timestamp/1000;

}

void CHandler::UpdateRightImage(SImgData img)
{
    cv::imshow("Right", img.frame);
    cv::waitKey(1);
    LOG(INFO) << "Right frame_id: " << img.frame_id << "  ,Right time: " << img.timestamp/1000;

}

void CHandler::UpdateIMU(SImuData& imu)
{
    LOG(INFO) << "Imu frame_id: " << imu.frame_id
                << ", timestamp: " << imu.timestamp/1000
                << ", accel_x: " << imu.accel[0]
                << ", accel_y: " << imu.accel[1]
                << ", accel_z: " << imu.accel[2]
                << ", gyro_x: " << imu.gyro[0]
                << ", gyro_y: " << imu.gyro[1]
                << ", gyro_z: " << imu.gyro[2]
                << ", temperature: " << imu.temperature;
}