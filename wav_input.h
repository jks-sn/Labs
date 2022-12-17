//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include <cstring>
#include <vector>

class wavRead {
public:
    explicit wavRead(std::string &inpath);



    std::string readFourBytes();

    bool isFileEnd();

    ~wavRead();

    int getPosition();

    void setFlagToPlace(size_t i);
    void setFlagToEnd();

    std::ifstream finput;

};
