cmake_minimum_required(VERSION 3.24)
project(image)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)
add_subdirectory(Core)
add_subdirectory(SimpleTriangle)