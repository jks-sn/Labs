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
#include <cstring>
#include <sstream>
const size_t BiggestWeight = 50;
const size_t BiggestHeight = 50;
const int numberExampleUnivercity = 2;
class LifeException : public std::exception {
public:
    explicit LifeException(std::string error) : error_(std::move(error)) {}

    const char *what() const noexcept override { return error_.c_str(); }

private:
    std::string error_;
};

class Life {
public:
    explicit Life() = default;

    explicit Life(std::ifstream &);

    Life(const std::vector<bool> &univercity_, size_t weight_, size_t height_);

    Life(const std::vector<bool> &univercity_, std::array<bool, 9> when_survival_, std::array<bool, 9> when_birth_,
         size_t weight, size_t height);

    void RecountNeigbours();

    void RecheckLife();

    void PrintBoard();

    void PrintBoard(std::ofstream &);
    void PrintBoard(std::stringstream &soutput);

    void RunLife(unsigned long int index);

    void CountNeigbours(const size_t &);

    ~Life() = default;

    void at(long long x, long long y);

    void FileParsing(std::ifstream &finput);
    void getNeighbours(std::stringstream &soutput);
private:
    size_t height_; //как сделать конст\static  и т.д.
    size_t weight_;
    std::string name;
    std::array<bool, 9> when_survival;
    std::array<bool, 9> when_birth;
    std::vector<unsigned char> neighbours;
    std::vector<bool> univercity;

};
