# cmake -D ENABLE_MYNT_SDK=ON .. 
cmake_minimum_required(VERSION 3.1)
project(driver VERSION 1.0.0 LANGUAGES C CXX)

####### Choose driver type: mynteye, ROS ... #######
option (ENABLE_MYNT_SDK "Enable MYNT SDK" ON)
option (ENABLE_MYNT_ROS "Enable MYNT ROS driver." OFF)

#################################################

############ Choose Release or Debug ##############
set(COMPILE_TYPE Release)
if(COMPILE_TYPE STREQUAL "Release")
  set(CMAKE_BUILD_TYPE "Release")
  set(CMAKE_CXX_FLAGS "-std=c++11")
  #-DEIGEN_USE_MKL_ALL")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")
elseif(COMPILE_TYPE STREQUAL "Debug")
  SET(CMAKE_BUILD_TYPE "Debug")
  SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
else()
  message(FATAL_ERROR "COMPILE_TYPE is Error!")
endif()
  message(WARNING "COMPILE_TYPE = ${COMPILE_TYPE}") 
#################################################

################# some setting ##################

#below setting is used to find _build/config.h
# set(CMAKE_INCLUDE_CURRENT_DIR ON) 
include_directories(${PROJECT_BINARY_DIR})

if (ENABLE_MYNT_SDK)
  set(DRIVER_TYPE mynteye)
elseif(ENABLE_MYNT_ROS)
  include_directories(${catkin_INCLUDE_DIRS})
  catkin_package()
  set(DRIVER_TYPE ${catkin_LIBRARIES})
endif()

#################################################

############# find relevant packages ############
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
message(WARNING "OpenCV_VERSION: ${OpenCV_VERSION}")

set(MINIGLOG_PATH ${PROJECT_SOURCE_DIR}/miniglog)
###libminiglog.dylib for Mac and libminiglog.so for Linux in below line.
set(MINIGLOG_LIBS ${MINIGLOG_PATH}/build/lib/libminiglog.so) 
set(MINIGLOG_INCLUDE_DIRS ${MINIGLOG_PATH}/build/include)

#################################################

################# add source ####################
include_directories( ${MINIGLOG_INCLUDE_DIRS})

aux_source_directory(. DIR_SRCS)
add_subdirectory(driver)
add_subdirectory(util)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

#################################################

################# add library ###################
add_library(handler_lib handler/handler.cpp)

#################################################

############### generate target #################
add_executable(driver_demo ${DIR_SRCS})
target_link_libraries(driver_demo
                      driver_lib 
                      handler_lib
                      util_lib
                      ${DRIVER_TYPE}
                      ${MINIGLOG_LIBS}
                      pthread     # pthread or ${CMAKE_THREAD_LIBS_INIT}
                      ${OpenCV_LIBS})
#################################################


