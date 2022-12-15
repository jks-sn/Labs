//
// Created by User on 11.12.2022.
//

#include "wav_input.h"

wavRead::wavRead(std::string &inpath) {
    this->finput.open(inpath, std::ios::in | std::ios::binary);
    if (!this->finput.is_open()) {
        throw std::invalid_argument("Error, can't open file for input");
    }
}

void wavRead::readSecond(sample *buffer, size_t FREQ) {
    for (int i = 0; i < FREQ; ++i) {
        this->finput.read(buffer[i].buffer_, 2);
    }
}

std::string wavRead::readFourBytes() {
    char data[4];
    this->finput.read(data, 4);
    return data;
}

wavRead::~wavRead() {
    this->finput.close();
}
void wavRead::setFlagToPlace(size_t i)
{
    this->finput.seekg(i,(this->finput).beg);
}
void wavRead::readSomeData(std::string& buffer,size_t size) {
    char data[size];
    this->finput.read(data, size);
    buffer.assign(data,data+size);
}

bool wavRead::isFileEnd() {
    return finput.eof();
}
