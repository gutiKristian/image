cmake_minimum_required(VERSION 3.24)

project(SimpleShader)

add_executable(SimpleShader src/main.cpp src/SimpleShaderLayer.h src/SimpleShaderLayer.cpp)

target_link_libraries(SimpleShader PUBLIC Core)

target_include_directories(SimpleShader PUBLIC ${CMAKE_SOURCE_DIR}/Core/src)