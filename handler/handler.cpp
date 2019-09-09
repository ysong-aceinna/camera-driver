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
          /*
      for (auto &&data : motion_datas) {
        LOG(INFO) << "Imu frame_id: " << data.imu->frame_id
                  << ", timestamp: " << data.imu->timestamp
                  << ", accel_x: " << data.imu->accel[0]
                  << ", accel_y: " << data.imu->accel[1]
                  << ", accel_z: " << data.imu->accel[2]
                  << ", gyro_x: " << data.imu->gyro[0]
                  << ", gyro_y: " << data.imu->gyro[1]
                  << ", gyro_z: " << data.imu->gyro[2]
                  << ", temperature: " << data.imu->temperature;
      }
      */

}

    //   painter.DrawImgData(img, *left_data.img);
    //   if (!motion_datas.empty() && motion_datas.size() > 0) {
    //     painter.DrawImuData(img, *motion_datas[0].imu);
    //   }

    //   cv::imshow("frame", img);
