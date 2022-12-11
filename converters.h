//
// Created by User on 10.12.2022.
//
#pragma once
#include <iostream>
#include <vector>
class converter{
public:
    virtual void do_something(std::istream &, std::ostream &, std::vector<int> &) = 0;
};
class mute: public converter
{
    void do_something(std::istream &, std::ostream &, std::vector<int> &) override ;
};
class mix: public converter
{
    void do_something(std::istream &, std::ostream &, std::vector<int> &) override ;
};
