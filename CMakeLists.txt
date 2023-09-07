cmake_minimum_required(VERSION 3.10)

project(ImageProcessingLibrary)

set(CMAKE_BUILD_TYPE Debug)

add_executable(app main.c)

add_subdirectory(API)

target_link_libraries(app PRIVATE api_library)