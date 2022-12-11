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
class SoundProcessor {
public:
    SoundProcessor(std::string&,
                   std::string&,
                   const std::vector<std::string>&);
    void start();

private:
    std::ifstream config_file;
    std::ofstream output_file;
    std::vector<std::ifstream> input_files;
};