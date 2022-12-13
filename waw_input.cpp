//
// Created by User on 11.12.2022.
//

#include "waw_input.h"

wawRead::wawRead(std::string &inpath) {
    this->finput.open(inpath, std::ios::in | std::ios::binary);
    if (!this->finput.is_open()) {
        throw std::invalid_argument("Error, can't open file for input");
    }
}

void wawRead::readSecond(sample *buffer, size_t FREQ) {
    for (int i = 0; i < FREQ; ++i) {
        this->finput.read(buffer[i].buffer_, 2);
    }
}

std::string wawRead::readHeader() {
    char data[4];
    this->finput.read(data, 4);
    return data;
}

wawRead::~wawRead() {
    this->finput.close();
}

std::string wawRead::readSomeData(size_t size) {
    char buffer[size];
    this->finput.read(buffer, size);
    return buffer;
}

bool wawRead::isFileEnd() {
    return finput.eof();
}
