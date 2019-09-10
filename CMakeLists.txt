cmake_minimum_required(VERSION 3.1)
project(driver VERSION 1.0.0 LANGUAGES C CXX)

############ set Release or Debug ##############
set(COMPILE_TYPE Debug)
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
  message(WARNING "COMPILE_TYPE = ${COMPILE_TYPE}") #make this msg highlight. 
#################################################

### set driver type: mynteye, ROS.
set(DRIVER_TYPE mynteye)

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


