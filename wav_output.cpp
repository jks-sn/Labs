//
// Created by User on 11.12.2022.
//

#include "wav_output.h"

wavWrite::wavWrite(std::string &outpath) {
    this->foutput.open(outpath, std::ios::in | std::ios::binary);
    if (!this->foutput.is_open()) {
        throw std::invalid_argument("Error, can't open file for output");
    }
}

void wavWrite::writeSecond(sample *buffer, size_t FREQ) {
    for (int i = 0; i < FREQ; ++i) {
        this->foutput.write(buffer[i].buffer_, 2);
    }
}

void wavWrite::writeFourBytes(std::string &data) {
    this->foutput.write(data.c_str(), 4);
}

wavWrite::~wavWrite() {
    this->foutput.close();
}

void wavWrite::writeSomeData(std::string&data, size_t size) {
    (this->foutput)<<data;
}

