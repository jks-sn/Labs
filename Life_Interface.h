//
// Created by User on 24.10.2022.
//
#pragma once
#include "Life_Core.h"
using namespace life;
const size_t maxNumberTicks = 1e9;
class interface {
public:
    virtual void interface_() = 0;
    static std::string getNumberExample(std::string &buffer);
    void getInputFile(std::ifstream &finput);
    static void startGame();
};

class interface_online : public interface {
public:
    void interface_() override;
};

class interface_offline : public interface {
public:
    void interface_() override;
    unsigned int getNumberIterations();
    unsigned int iterationsFromStringToInt(std::string &buffer);
    void getOutputFile(std::ofstream &foutput);
};
