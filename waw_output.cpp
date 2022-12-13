//
// Created by User on 11.12.2022.
//

#include "waw_output.h"

wawWrite::wawWrite(std::string &outpath) {
    this->foutput.open(outpath, std::ios::in | std::ios::binary);
    if (!this->foutput.is_open()) {
        throw std::invalid_argument("Error, can't open file for output");
    }
}

void wawWrite::writeSecond(sample *buffer, size_t FREQ) {
    for (int i = 0; i < FREQ; ++i) {
        this->foutput.write(buffer[i].buffer_, 2);
    }
}

void wawWrite::writeHeader(std::string &data) {
    this->foutput.write(data.c_str(), 4);
}

wawWrite::~wawWrite() {
    this->foutput.close();
}

void wawWrite::writeSomeData(std::string &data, size_t size) {
    this->foutput.write(data.c_str(), size);
}

