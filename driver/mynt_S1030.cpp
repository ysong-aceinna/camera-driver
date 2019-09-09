/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
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

  auto request = m_api->GetStreamRequest();
  request.width = 376;
  request.height = 240;
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
      imu.temperature = data.imu->temperature;
      m_phandler->UpdateIMU(imu);
    }
    // std::chrono::milliseconds dura(2);
    // std::this_thread::sleep_for(dura);
  }
}
