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
};

class mute : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;
};

class mix : public converter {
    void do_something(std::string &, std::string &, std::vector<std::string> &) override;
};
