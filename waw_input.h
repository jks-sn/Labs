//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

class wawRead {
public:
    explicit wawRead(std::string &inpath);

    void readSecond(sample *buffer, size_t FREQ);

    std::string readSomeData(size_t size);

    std::string readFourBytes();

    bool isFileEnd();

    ~wawRead();

private:
    std::ifstream finput;
};
