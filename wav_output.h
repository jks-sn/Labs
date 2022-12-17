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


    void writeSomeData(std::string&data, size_t );

    void writeFourBytes(std::string &);

    ~wavWrite();

private:
    std::ofstream foutput;
};