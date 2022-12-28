//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

namespace wavconverter {
    class WavRead {
        friend class Converter;

    public:
        explicit WavRead(std::string &inpath);

        void readSecond(Sample *buffer, size_t FREQ);


        bool isFileEnd();

        ~WavRead();

        void setFlagToPlace(size_t i);

        void setFlagToEnd();

        int getPosition();

        int getSizeFile();


    private:

        std::ifstream finput;
    };
}
