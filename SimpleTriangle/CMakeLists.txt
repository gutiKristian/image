cmake_minimum_required(VERSION 3.24)

project(SimpleTriangle)

add_executable(SimpleTriangle src/main.cpp src/DummyLayer.cpp src/DummyLayer.h)

target_link_libraries(SimpleTriangle PUBLIC Core)

target_include_directories(SimpleTriangle PUBLIC ${CMAKE_SOURCE_DIR}/Core/src)