//
// Created by User on 11.12.2022.
//

#include "wav_output.h"

using namespace wavconverter;

wavconverter::WavWrite::WavWrite(std::string &outpath) {
    this->foutput.open(outpath, std::ios::in | std::ios::binary);
    if (!this->foutput.is_open()) {
        throw std::invalid_argument("Error, can't open file for output");
    }
}

void wavconverter::WavWrite::writeSecond(Sample *buffer, size_t FREQ) {
    char buffer_[BytesPerSample];
    for (int i = 0; i < FREQ; ++i) {
        (buffer[i]).getSample(buffer_);
        this->foutput.write(buffer_, BytesPerSample);
    }
}

wavconverter::WavWrite::~WavWrite() {
    this->foutput.close();
}


