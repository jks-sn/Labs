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


void wavWrite::writeFourBytes(std::string &data) {
    this->foutput.write(data.c_str(), 4);
}

wavWrite::~wavWrite() {
    this->foutput.close();
}


