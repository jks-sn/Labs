//
// Created by User on 11.12.2022.
//
#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "converters_factory.h"
#include "waw_input.h"
#include "waw_output.h"
#include "config.h"
class SoundProcessor {
public:
    void start(std::string &config_file_, std::string &output_file_,
               std::vector<std::string>& input_files_);
};