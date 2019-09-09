/*******************************************************
 * Copyright (C) 2019
 *
 * Author: SongYang (ysong@aceinna.com)
 *******************************************************/
#pragma once
#include <opencv2/highgui/highgui.hpp>
#include "mynteye/logger.h"
#include "mynteye/api/api.h"
// #include "util/cv_painter.h"

#include "driver.h"

MYNTEYE_USE_NAMESPACE

class CMyntS1030Driver : public CDriverBase
{
private:
  std::shared_ptr<API> m_api;
public:
  CMyntS1030Driver();
  ~CMyntS1030Driver();

    virtual int Init();
    virtual void Start();
    virtual void Stop();
    virtual void ThreadGetData();
    // void ThreadGetData();
};
