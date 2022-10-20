//
// Created by User on 10.10.2022.
//
#pragma once
#include <fstream>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
class LifeException: public std::exception
{
public:
    explicit LifeException(std::string error): error_(std::move(error))
    {}
    const char* what() const noexcept override { return error_.c_str(); }
private:
    std::string error_;
};
class Life{
public:
    explicit Life();
    explicit Life(std::ifstream& input);
    void CheckNeigbours();
    unsigned char SummNeigbours(const size_t &index)
    ~Life() = default;
    void at(long long &x, long long &y);
    size_t height_; //как сделать конст\static  и т.д.
    size_t weight_;
    std::string name;
    std::array<bool,9> when_survival;
    std::array<bool,9> when_birth;
    std::vector<unsigned char> neighbours;
    std::vector<bool> univercity;
};
