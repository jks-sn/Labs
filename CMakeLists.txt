cmake_minimum_required(VERSION 3.21)
project(Labs)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
set(Sources main.cpp wav_class.cpp wav_class.h sample.h converters_factory.h converters.cpp converters.h converters_factory.cpp SoundProcessor.cpp SoundProcessor.h)
add_executable(Labs ${Sources})
target_link_libraries(Labs gtest)
