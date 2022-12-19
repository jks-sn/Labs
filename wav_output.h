//
// Created by User on 11.12.2022.
//
#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

namespace wavconverter {
    class wavWrite {
        friend class converter;

    public:
        explicit wavWrite(std::string &outpath);

        void writeSecond(sample *buffer, size_t FREQ);

        void writeSomeData(std::string &data, size_t);

        void writeFourBytes(std::string &);

        ~wavWrite();


    private:
        std::ofstream foutput;
    };
}
