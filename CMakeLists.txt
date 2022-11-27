cmake_minimum_required(VERSION 3.21)
project(Labs)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
set(Sources main.cpp waw_class.cpp waw_class.h)
add_executable(Labs ${Sources})
target_link_libraries(Labs gtest)
