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
    void writeSomeData(char *data, size_t size);
    void writeHeader(char *data);

    ~wawWrite();
private:
    std::ofstream foutput;
};