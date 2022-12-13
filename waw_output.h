//
// Created by User on 11.12.2022.
//
#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

class wawWrite {
public:
    explicit wawWrite(std::string &outpath);

    void writeSecond(sample *buffer, size_t FREQ);

    void writeSomeData(std::string &, size_t size);

    void writeFourBytes(std::string &data);

    ~wawWrite();

private:
    std::ofstream foutput;
};