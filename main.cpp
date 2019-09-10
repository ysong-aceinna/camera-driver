/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#include "handler/handler.h"
#include "driver/mynt_S1030.h"

int main(int argc, char *argv[])
{
  CHandler* phandler = new CHandler();
  CDriverBase* pdriver = new CMyntS1030Driver();
  pdriver->ReadParameters("/mnt/wind/project/camera-driver/mynt_mono_config.yaml");
  pdriver->AddListener(phandler);
  pdriver->Init();
  pdriver->Start();
  sleep(2000000);
  pdriver->Stop();

  #if 0  //test restart stream.
  sleep(2);
  LOG(INFO) << "Restart ...";
  pdriver->Start();
  sleep(5);
  pdriver->Stop();
  sleep(2);
  LOG(INFO) << "Restart ...";
  pdriver->Start();
  sleep(5);
  pdriver->Stop();
  #endif
  
  SAFEDELETE(pdriver);
  SAFEDELETE(phandler);
  return 0;
}
