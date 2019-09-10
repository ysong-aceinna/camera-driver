cmake_minimum_required(VERSION 3.0)

project(driver VERSION 1.0.0 LANGUAGES C CXX)

set(COMPILE_TYPE Release)  #Debug Release
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

find_package(OpenCV REQUIRED)
message(WARNING "OpenCV_VERSION: ${OpenCV_VERSION}")


add_executable(driver_demo driver_demo.cpp)
target_link_libraries(driver_demo  mynteye ${OpenCV_LIBS})
