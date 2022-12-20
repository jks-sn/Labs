//
// Created by User on 11.12.2022.
//

#include "wav_input.h"
using namespace wavconverter;
wavconverter::wavRead::wavRead(std::string &inpath) {
    this->finput.open(inpath, std::ios::binary);
    if (!this->finput.is_open()) {
        throw std::invalid_argument("Error, can't open file for input");
    }
}

void wavconverter::wavRead::readSecond(sample *buffer, size_t FREQ) {
    char buffer_[bytesPerSample];
    for (int i = 0; i < FREQ; ++i) {
        this->finput.read(buffer_, bytesPerSample);
        (buffer[i]).setSample(buffer_[0],buffer_[1]);
    }
}

/*std::string wavconverter::wavRead::readFourBytes() {
    char data[4];
    this->finput.read(data, 4);
    return data;
}*/

wavconverter::wavRead::~wavRead() {
    this->finput.close();
}
void wavconverter::wavRead::setFlagToPlace(size_t i)
{
    this->finput.seekg(i,std::ios::beg);
}
/*void wavconverter::wavRead::readSomeData(std::string& buffer,size_t size) {
    char data[size];
    this->finput.read(data, size);
    buffer.assign(data,data+size);
}*/

bool wavconverter::wavRead::isFileEnd() {
    return finput.eof();
}
void wavconverter::wavRead::setFlagToEnd() {
    this->finput.clear();
    this->finput.seekg(0,this->finput.end);
}

int wavconverter::wavRead::getPosition()
{
    return this->finput.tellg();
};
int wavconverter::wavRead::getSizeFile()
{
    int buffer = this->getPosition();
    this->setFlagToEnd();
    int answer = this->getPosition();
    this->setFlagToPlace(buffer);
    return answer;
}