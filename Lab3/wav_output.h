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
        friend class Converter;

    public:
        explicit WavWrite(std::string &outpath);

        void writeSecond(Sample *buffer, size_t FREQ);
        

        ~WavWrite();


    private:
        std::ofstream foutput;
    };
}
