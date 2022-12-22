//
// Created by User on 11.12.2022.
//

#include "wav_input.h"

using namespace wavconverter;

wavconverter::WavRead::WavRead(std::string &inpath) {
    this->finput.open(inpath, std::ios::binary);
    if (!this->finput.is_open()) {
        throw std::invalid_argument("Error, can't open file for input");
    }
}

void wavconverter::WavRead::readSecond(Sample *buffer, size_t FREQ) {
    char buffer_[BytesPerSample];
    for (int i = 0; i < FREQ; ++i) {
        this->finput.read(buffer_, BytesPerSample);
        (buffer[i]).setSample(buffer_[0], buffer_[1]);
    }
}

wavconverter::WavRead::~WavRead() {
    this->finput.close();
}

void wavconverter::WavRead::setFlagToPlace(size_t i) {
    this->finput.seekg(i, std::ios::beg);
}

bool wavconverter::WavRead::isFileEnd() {
    return finput.eof();
}

void wavconverter::WavRead::setFlagToEnd() {
    this->finput.clear();
    this->finput.seekg(0, this->finput.end);
}

int wavconverter::WavRead::getPosition() {
    return this->finput.tellg();
};

int wavconverter::WavRead::getSizeFile() {
    int buffer = this->getPosition();
    this->setFlagToEnd();
    int answer = this->getPosition();
    this->setFlagToPlace(buffer);
    return answer;
}