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
  CMyntS1030Driver* pdriver = new CMyntS1030Driver();
  pdriver->AddListener(phandler);
  return 0;
}
