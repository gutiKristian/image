cmake_minimum_required(VERSION 3.25)
cmake_minimum_required(VERSION 3.25)
project(image)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_FILES src/stb.h)



set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "libs/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS "system" window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} "sfml-system" sfml-window sfml-graphics sfml-audio)