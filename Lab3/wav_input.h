//
// Created by User on 11.12.2022.
//

#pragma once

#include <string>
#include <fstream>
#include "sample.h"
#include <cstring>

namespace wavconverter {
    class wavRead {
        friend class converter;

    public:
        explicit wavRead(std::string &inpath);

        void readSecond(sample *buffer, size_t FREQ);

        void readSomeData(std::string &buffer, size_t size);

        std::string readFourBytes();

        bool isFileEnd();

        ~wavRead();

        void setFlagToPlace(size_t i);

        void setFlagToEnd();

        int getPosition();

        int getSizeFile();


    private:

        std::ifstream finput;
    };
}
