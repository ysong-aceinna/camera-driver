
#pragma once

#include <thread>
#include <mutex>
// #include <pthread.h>

#include "../handler/handler.h"
#include "struct.h"

class CDriverBase
{
protected:
    int m_fps;        // frames per second of images
    int m_odr;        // odr of imu
    int m_width;      // width of image
    int m_height;     // height of image
   
    bool m_use_imu;
    bool m_bmono;
    CHandler* m_phandler;
    std::thread m_get_data_thread;

public:
    CDriverBase(){}
    ~CDriverBase(){}

    void SetParameters(int fps, int odr, int width, int height, bool use_imu, bool b_mono)
    {
        m_fps = fps;
        m_odr = odr;
        m_width = width;
        m_height = height;        
        m_use_imu = use_imu;
        m_bmono = b_mono;
    }

    void GetParameters(int& fps, int& odr, int& width, int& height)
    {
       fps = m_fps;
       odr = m_odr;
       width = m_width;
       height = m_height;        
    }

    virtual int Init() = 0;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    // virtual void ThreadGetData() = 0;
    void AddListener(CHandler* phandler){m_phandler = phandler;}

};
