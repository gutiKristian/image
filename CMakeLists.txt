cmake_minimum_required(VERSION 3.24)
project(image)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES src/stb.h)
file(GLOB GraphicsModule CONFIGURE_DEPENDS "src/graphics/*.ixx")
file(GLOB VisionModule CONFIGURE_DEPENDS "src/vision/*.ixx")

add_subdirectory(external/glfw)
add_executable(${PROJECT_NAME} src/main.cpp ${GraphicsModule} ${VisionModule} ${HEADER_FILES})