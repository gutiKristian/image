cmake_minimum_required(VERSION 3.25)
project(image)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES src/stb.h)



set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "libs/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS "system" window graphics audio REQUIRED)

file(GLOB ImGui CONFIGURE_DEPENDS "src/imgui/*.h" "src/imgui/*.cpp")


add_executable(${PROJECT_NAME} src/main.cpp src/basics.ixx ${HEADER_FILES} ${ImGui})
target_link_libraries(${PROJECT_NAME} "sfml-system" sfml-window sfml-graphics sfml-audio)