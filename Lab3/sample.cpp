//
// Created by User on 15.12.2022.
//
#include "sample.h"
using namespace wavconverter;
int wavconverter::Sample::sampleToInt() {
    int buffer;
    if (this->buffer_[0] & (maskForCheckFirstByteOfChar)) {
        this->buffer_[0] = this->buffer_[0] & maskForSetZeroToFirstByteOfChar;
        buffer = (static_cast<int>(this->buffer_[1]) << sizeChar);
        buffer += this->buffer_[0];
        changeDopCode(buffer);
    } else {
        buffer = (static_cast<int>(this->buffer_[1]) << sizeChar);
        buffer += this->buffer_[0];
    }
    return buffer;
}

void wavconverter::Sample::intToSample(int data) {
    if (data > 0) {
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>(data >> sizeChar);
    } else {
        changeDopCode(data);
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>((data >> sizeChar) | maskForSetOneToFirstByteOfChar);
    }
}
void wavconverter::Sample::setSample(char& a, char & b){
    this->buffer_[0] = a;
    this->buffer_[1] = b;
}
void wavconverter::Sample::getSample(char *buffer)
{
    buffer[0] = this->buffer_[0];
    buffer[1] = this->buffer_[1];
}
wavconverter::Sample::Sample(){
    buffer_[0] = 0;
    buffer_[1] = 0;
}

void wavconverter::Sample::changeDopCode(int &buffer) {
    buffer = ~(buffer)+1;
}
