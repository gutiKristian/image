cmake_minimum_required(VERSION 3.24)

project(VolumeRender)

add_executable(VolumeRender src/main.cpp src/DummyLayer.h)

target_link_libraries(VolumeRender PUBLIC Core)

target_include_directories(VolumeRender PUBLIC ${CMAKE_SOURCE_DIR}/Core/src)