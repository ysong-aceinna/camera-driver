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

void CHandler::UpdateLeftImage(cv::Mat img)
{
    cout << "UpdateLeftImage" << endl;
}

void CHandler::UpdateRightImage(cv::Mat img)
{
    cout << "UpdateRightImage" << endl;
}

void CHandler::UpdateIMU(SImuData& imu)
{
    cout << "UpdateIMU" << endl;
    LOG(INFO) << "Imu frame_id: " << imu.frame_id
                << ", timestamp: " << imu.timestamp
                << ", accel_x: " << imu.accel[0]
                << ", accel_y: " << imu.accel[1]
                << ", accel_z: " << imu.accel[2]
                << ", gyro_x: " << imu.gyro[0]
                << ", gyro_y: " << imu.gyro[1]
                << ", gyro_z: " << imu.gyro[2]
                << ", temperature: " << imu.temperature;
}

    //   painter.DrawImgData(img, *left_data.img);
    //   if (!motion_datas.empty() && motion_datas.size() > 0) {
    //     painter.DrawImuData(img, *motion_datas[0].imu);
    //   }

    //   cv::imshow("frame", img);
