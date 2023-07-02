cmake_minimum_required(VERSION 3.25)
project(image)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_FILES src/stb.h)

add_executable(${PROJECT_NAME} src/main.cpp ${HEADER_FILES})
