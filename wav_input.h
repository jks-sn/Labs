//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

class wavRead {
public:
    explicit wavRead(std::string &inpath);

    void readSecond(sample *buffer, size_t FREQ);

    void readSomeData(std::string& buffer, size_t size);

    std::string readFourBytes();

    bool isFileEnd();

    ~wavRead();

    void setFlagToPlace(size_t i);

private:
    std::ifstream finput;
};
