//
// Created by User on 15.12.2022.
//
#include "sample.h"
int sample::sampleToInt() {
    int buffer;
    if (this->buffer_[0] & (0x01 << 8)) {
        this->buffer_[0] = this->buffer_[0] & 0x7F;
        buffer = (static_cast<int>(this->buffer_[1]) << 8);
        buffer += this->buffer_[0];
        buffer = (~buffer) + 1;
    } else {
        buffer = (static_cast<int>(this->buffer_[1]) << 8);
        buffer += this->buffer_[0];
    }
    return buffer;
}

void sample::intToSample(int data) {
    if (data > 0) {
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>(data >> 8);
    } else {
        data = (~data) + 1;
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>((data >> 8) | 128);
    }
}
void sample::setSample(char& a, char & b){
    this->buffer_[0] = a;
    this->buffer_[1] = b;
};
void sample::getSample(char *buffer)
{
    buffer[0] = this->buffer_[0];
    buffer[1] = this->buffer_[1];
}
sample::sample(){
    buffer_[0] = 0;
    buffer_[1] = 0;
}
