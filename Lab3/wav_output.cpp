//
// Created by User on 11.12.2022.
//

#include "wav_output.h"
using namespace wavconverter;
wavconverter::wavWrite::wavWrite(std::string &outpath) {
    this->foutput.open(outpath, std::ios::in | std::ios::binary);
    if (!this->foutput.is_open()) {
        throw std::invalid_argument("Error, can't open file for output");
    }
}

void wavconverter::wavWrite::writeSecond(sample *buffer, size_t FREQ) {
    char buffer_[2];
    for (int i = 0; i < FREQ; ++i) {
        (buffer[i]).getSample(buffer_);
        this->foutput.write(buffer_, 2);
    }
}

void wavconverter::wavWrite::writeFourBytes(std::string &data) {
    this->foutput.write(data.c_str(), 4);
}

wavconverter::wavWrite::~wavWrite() {
    this->foutput.close();
}

void wavconverter::wavWrite::writeSomeData(std::string&data, size_t size) {
    (this->foutput)<<data;
}

