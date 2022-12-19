//
// Created by User on 11.12.2022.
//
#pragma once

#include <vector>
#include <stdexcept>
#include <sstream>
#include "converters_factory.h"
#include "wav_input.h"
#include "wav_output.h"
#include "config.h"
class SoundProcessor {
public:
    static void start(std::string &config_file_, std::string &output_file_,
                      std::vector<std::string> &input_files_);
};