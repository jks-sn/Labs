//
// Created by User on 11.12.2022.
//
#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

class wavWrite {
public:
    explicit wavWrite(std::string &outpath);

    void writeSecond(sample *buffer, size_t FREQ);

    void writeSomeData(std::string&data, size_t );

    void writeFourBytes(std::string &);

    ~wavWrite();
    friend class converter;
private:
    std::ofstream foutput;
};