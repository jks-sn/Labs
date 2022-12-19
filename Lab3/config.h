//
// Created by User on 13.12.2022.
//
#pragma once

#include <fstream>
#include <string>
#include "sample.h"
#include <vector>
#include <iostream>

namespace wavconfig {
    class config {
    public:
        explicit config(std::string &);

        std::string getConvert();

        std::vector<std::string> readArgumentConvert(std::string &);

        ~config();

    private:
        std::ifstream config_;
    };
}