//
// Created by User on 10.12.2022.
//
#pragma once

#include <array>
#include <cstdint>
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
/*        void intToSample(int);

        int sampleToInt();*/

        void setSample(int16_t);

        int16_t getSample();

    private:
        int16_t buffer_;

    };
}