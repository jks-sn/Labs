//
// Created by User on 10.12.2022.
//
#pragma once
#include <iostream>
#include <vector>
#include "wav_output.h"
#include "wav_input.h"
#include "sample.h"
const size_t FREQ = 44100;
class converter {
public:
    virtual void do_something(std::string &, std::string &, std::vector<std::string> &) = 0;

    void writeAndReadHeader(wavRead &, wavWrite &);

    void fillToEnd(wavRead &, wavWrite &);

    void jump(wavRead &, wavWrite &, int );

};

class mute : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;
};

class mix : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;

    void mixSecond(sample *input1, sample *input2);
};
