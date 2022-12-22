//
// Created by User on 10.12.2022.
//
#pragma once

#include <array>
namespace wavconverter {
    const unsigned int BytesPerSample = 2;
    const int BytesPerSample_int = 2;
    const int MaskForCheckFirstByteOfChar = 0x01 << 8;
    const int MaskForSetZeroToFirstByteOfChar = 0x7F;
    const int MaskForSetOneToFirstByteOfChar = 128;
    const int SizeChar = 8;
    class Sample {
    public:
        explicit Sample();
        void changeDopCode(int &buffer);
        void intToSample(int);

        int sampleToInt();

        void setSample(char &, char &);

        void getSample(char *);

    private:
        char buffer_[BytesPerSample]{};

    };
}