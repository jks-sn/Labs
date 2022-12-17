//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include <cstring>

class wavRead {
public:
    explicit wavRead(std::string &inpath);


    void readSomeData(std::string& buffer, size_t size);

    std::string readFourBytes();

    bool isFileEnd();

    ~wavRead();

    int getPosition();

    void setFlagToPlace(size_t i);
    void setFlagToEnd();

private:
    std::ifstream finput;

};
