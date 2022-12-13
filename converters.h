//
// Created by User on 10.12.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "waw_output.h"
#include "waw_input.h"
#include "sample.h"

class converter {
public:
    virtual void do_something(std::string &, std::string &, std::vector<std::string> &) = 0;

    void writeAndReadHeader(wawRead &, wawWrite &);

    void fillToEnd(wawRead &, wawWrite &);

    void jump(wawRead &, wawWrite &, int );

    void intToSample(int , sample *);

    int sampleToInt(sample &);
};

class mute : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;
};

class mix : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;

    void mixSecond(sample *input1, sample *input2);
};
