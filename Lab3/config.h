//
// Created by User on 13.12.2022.
//
#pragma once

#include <fstream>
#include <string>
#include "sample.h"
#include <vector>
#include <iostream>
namespace wavconfig  {
    const std::string MessageOfEndConfig = "config_end";
    class Config {
    public:
        explicit Config(std::string &);

        std::string getConvert();

        std::vector<std::string> readArgumentConvert(unsigned int number_arguments);

        ~Config();

    private:
        std::ifstream config_;
    };
}