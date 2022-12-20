//
// Created by User on 10.12.2022.
//
#pragma once

#include <array>
namespace wavconverter {
    const unsigned int bytesPerSample = 2;
    const int bytesPerSample_int = 2;
    const int maskForCheckFirstByteOfChar = 0x01 << 8;
    const int maskForSetZeroToFirstByteOfChar = 0x7F;
    const int maskForSetOneToFirstByteOfChar = 128;
    class sample {
    public:
        explicit sample();
        void changeDopCode(int &buffer);
        void intToSample(int);

        int sampleToInt();

        void setSample(char &, char &);

        void getSample(char *);

    private:
        char buffer_[bytesPerSample]{};

    };
}