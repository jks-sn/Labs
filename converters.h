//
// Created by User on 10.12.2022.
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "sample.h"
class converter{
public:
    virtual void do_something(std::string &, std::string &, std::vector<std::string>& ) = 0;
};
class mute: public converter
{
    void do_something(std::string &, std::string &, std::vector<std::string>& ) override ;
};
class mix: public converter
{
    void do_something(std::string &, std::string &, std::vector<std::string>& ) override ;
};
