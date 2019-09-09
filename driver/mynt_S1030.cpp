
#include "mynt_S1030.h"


CMyntS1030Driver::CMyntS1030Driver()
{
}

CMyntS1030Driver::~CMyntS1030Driver()
{
}

int CMyntS1030Driver::Init()
{
  m_api = API::Create(0, NULL);
  if (!m_api)
    return 1;

  bool ok;
  auto &&request = m_api->SelectStreamRequest(&ok);
  if (!ok)
    return 1;
  m_api->ConfigStreamRequest(request);
  return 0;
}

void CMyntS1030Driver::Start()
{
  m_get_data_thread = std::thread(&CMyntS1030Driver::ThreadGetData, this);
}

void CMyntS1030Driver::Stop()
{
  m_api->Stop(Source::ALL);
}

void CMyntS1030Driver::ThreadGetData()
{
  // Enable this will cache the motion datas until you get them.
  m_api->EnableMotionDatas();
  m_api->Start(Source::ALL);

  while (1)
  {
    m_api->WaitForStreams();

    auto &&left_data = m_api->GetStreamData(Stream::LEFT);
    if (!m_bmono)
    {
      auto &&right_data = m_api->GetStreamData(Stream::RIGHT);
      if (!right_data.frame.empty()) 
      {
        m_phandler->UpdateRightImage(right_data.frame);
      }
    }

    auto &&motion_datas = m_api->GetMotionDatas();
    
    if (!left_data.frame.empty()) 
    {
      m_phandler->UpdateLeftImage(left_data.frame);
    }

    for (auto &&data : motion_datas)
    {
      SImuData imu;
      imu.frame_id = data.imu->frame_id;
      imu.timestamp = data.imu->timestamp;
      memcpy(imu.accel, data.imu->accel, 3* sizeof(imu.accel[0]));
      memcpy(imu.gyro, data.imu->gyro, 3* sizeof(imu.gyro[0]));
      // imu.accel = data.imu->accel;
      // imu.gyro = data.imu->gyro;
      imu.temperature = data.imu->temperature;
      
      m_phandler->UpdateIMU(imu);
    }
    // std::chrono::milliseconds dura(2);
    // std::this_thread::sleep_for(dura);
  }
}


// int main(int argc, char *argv[]) {

//   CVPainter painter;

//   cv::namedWindow("frame");

//   while (true) {
//     m_api->WaitForStreams();

//     auto &&left_data = m_api->GetStreamData(Stream::LEFT);
//     auto &&right_data = m_api->GetStreamData(Stream::RIGHT);

//     if (!left_data.frame.empty() && !right_data.frame.empty()) {
//       cv::Mat img;
//       cv::hconcat(left_data.frame, right_data.frame, img);

//       auto &&motion_datas = m_api->GetMotionDatas();
//       /*
//       for (auto &&data : motion_datas) {
//         LOG(INFO) << "Imu frame_id: " << data.imu->frame_id
//                   << ", timestamp: " << data.imu->timestamp
//                   << ", accel_x: " << data.imu->accel[0]
//                   << ", accel_y: " << data.imu->accel[1]
//                   << ", accel_z: " << data.imu->accel[2]
//                   << ", gyro_x: " << data.imu->gyro[0]
//                   << ", gyro_y: " << data.imu->gyro[1]
//                   << ", gyro_z: " << data.imu->gyro[2]
//                   << ", temperature: " << data.imu->temperature;
//       }
//       */

//       painter.DrawImgData(img, *left_data.img);
//       if (!motion_datas.empty() && motion_datas.size() > 0) {
//         painter.DrawImuData(img, *motion_datas[0].imu);
//       }

//       cv::imshow("frame", img);
//     }

//     char key = static_cast<char>(cv::waitKey(1));
//     if (key == 27 || key == 'q' || key == 'Q') {  // ESC/Q
//       break;
//     }
//   }

//   m_api->Stop(Source::ALL);
//   return 0;
// }
