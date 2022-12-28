//
// Created by User on 15.12.2022.
//
#include "sample.h"
using namespace wavconverter;
/*
int wavconverter::Sample::sampleToInt() {
    int buffer;
    if (this->buffer_[0] & (MaskForCheckFirstByteOfChar)) {
        this->buffer_[0] = this->buffer_[0] & MaskForSetZeroToFirstByteOfChar;
        buffer = (static_cast<int>(this->buffer_[1]) << SizeChar);
        buffer += this->buffer_[0];
        changeDopCode(buffer);
    } else {
        buffer = (static_cast<int>(this->buffer_[1]) << SizeChar);
        buffer += this->buffer_[0];
    }
    return buffer;
}

void wavconverter::Sample::intToSample(int data) {
    if (data > 0) {
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>(data >> SizeChar);
    } else {
        changeDopCode(data);
        this->buffer_[1] = static_cast<char>(data);
        this->buffer_[0] = static_cast<char>((data >> SizeChar) | MaskForSetOneToFirstByteOfChar);
    }
    }
*/
void wavconverter::Sample::setSample(int16_t a){
    this->buffer_ = a;
}
int16_t wavconverter::Sample::getSample()
{
    return this->buffer_;
}
wavconverter::Sample::Sample(){
    this->buffer_ = 0;
}

void wavconverter::Sample::changeDopCode(int &buffer) {
    buffer = ~(buffer)+1;
}
