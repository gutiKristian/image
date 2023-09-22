cmake_minimum_required(VERSION 3.24)
project(Core)

# Gather all files in the Core directory and its subdirectories.
file(GLOB_RECURSE CORE_HEADERS  ${CMAKE_SOURCE_DIR}/Core/src/impl/*.h
                                ${CMAKE_SOURCE_DIR}/Core/src/layer/*.h
                                ${CMAKE_SOURCE_DIR}/Core/src/application/*.h
                                ${CMAKE_SOURCE_DIR}/Core/src/window/*.h
                                ${CMAKE_SOURCE_DIR}/Core/src/*.h
)

file(GLOB_RECURSE CORE_UNITS    ${CMAKE_SOURCE_DIR}/Core/src/impl/*.cpp
                                ${CMAKE_SOURCE_DIR}/Core/src/application/*.cpp
                                ${CMAKE_SOURCE_DIR}/Core/src/layer/*.cpp
                                ${CMAKE_SOURCE_DIR}/Core/src/window/*.cpp
                                ${CMAKE_SOURCE_DIR}/Core/src/*.cpp
)

add_library(Core STATIC ${CORE_HEADERS} ${CORE_UNITS})
target_include_directories(Core PUBLIC ${CORE_HEADERS})
target_include_directories(Core 
    PUBLIC external/glfw/include
)

target_link_directories(Core
    PUBLIC external/glfw/src/Debug
)

target_link_libraries(${PROJECT_NAME} glfw glad)