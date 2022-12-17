cmake_minimum_required(VERSION 3.21)
project(Labs)

set(CMAKE_CXX_STANDARD 14)
set(Sources main.cpp wav_class.cpp wav_class.h sample.h converters_factory.h converters.cpp converters.h converters_factory.cpp SoundProcessor.cpp SoundProcessor.h wav_input.cpp wav_input.h wav_output.cpp wav_output.h config.cpp config.h converters_functions.cpp sample.cpp)
add_executable(Labs ${Sources})