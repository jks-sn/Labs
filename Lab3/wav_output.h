//
// Created by User on 11.12.2022.
//
#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

namespace wavconverter {
    class WavWrite {
        friend class converter;

    public:
        explicit WavWrite(std::string &outpath);

        void writeSecond(Sample *buffer, size_t FREQ);

        void writeSomeData(std::string &data, size_t);

        void writeFourBytes(std::string &);

        ~WavWrite();


    private:
        std::ofstream foutput;
    };
}
