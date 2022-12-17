//
// Created by User on 11.12.2022.
//
#pragma once

#include <string>
#include <fstream>
#include <cstring>

class wavWrite {
public:
    explicit wavWrite(std::string &outpath);


    void writeFourBytes(std::string &);

    ~wavWrite();

    std::ofstream foutput;
};