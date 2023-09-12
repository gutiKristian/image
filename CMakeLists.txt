cmake_minimum_required(VERSION 3.24)
project(image)

set(CMAKE_CXX_STANDARD 20)

file(GLOB GraphicsModule CONFIGURE_DEPENDS "src/graphics/*.ixx")
file(GLOB VisionModule CONFIGURE_DEPENDS "src/vision/*.ixx")

add_subdirectory(external/glad)
add_subdirectory(external/glfw)
# add_executable(${PROJECT_NAME} src/main.cpp src/stb.h ${GraphicsModule} ${VisionModule})
add_executable(${PROJECT_NAME} src/main.cpp src/stb.h)


target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src/Debug
)

target_link_libraries(${PROJECT_NAME} glfw glad)
