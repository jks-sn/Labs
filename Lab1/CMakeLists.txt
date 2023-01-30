cmake_minimum_required(VERSION 3.21)
project(BigInt)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
set(Sources main.cpp BigInt.cpp BigInt.hpp)
add_executable(BigInt ${Sources})
target_link_libraries(BigInt gtest gtest_main)
