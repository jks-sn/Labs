//
// Created by User on 03.11.2022.
//
#include "Life_Core.h"

Life::Life(std::ifstream &finput) {
    std::fill(when_birth.begin(), when_birth.end(), false);
    std::fill(when_survival.begin(), when_survival.end(), false);
    std::string buffer;
    std::getline(finput, buffer);
    if (buffer != "#Life 1.06") {
        throw LifeException("Invalid format of file(first line)");
    }
    finput >> buffer;
    if (buffer != "#N") {
        throw LifeException("Invalid format of file(second line)");
    }
    std::getline(finput, this->name);
    finput >> buffer;
    if (buffer != "#R")
        throw LifeException("Invalid format of file(third line1)");
    finput >> buffer;
    if ((buffer.empty()) || (buffer[0] != 'B') || (buffer.find('/') == std::string::npos) ||
        ((buffer.find('/') + 1) == buffer.size()) || (buffer[(buffer.find('/') + 1)] != 'S'))
        throw LifeException("Invalid format of file(third line2)");
    for (size_t i = 1; i < buffer.find('/'); ++i) {
        if (!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line3");
        when_birth[static_cast <size_t>(buffer[i] - '0')] = true;
    }
    for (size_t i = (buffer.find('S') + 1); i < buffer.size(); ++i) {
        if (!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line4");
        when_survival[static_cast <size_t>(buffer[i] - '0')] = true;
    }
    finput >> buffer; //начали считывать размеер поля
    if (finput.eof())
        throw LifeException("Invalid format of file(no size of univercity(weight)");
    weight_ = std::stoul(buffer);
    finput >> buffer;
    if (finput.eof())
        throw LifeException("Invalid format of file(no size of univercity)(height)");
    height_ = std::stoul(buffer);
    if (height_ > 50 || weight_ > 50)
        throw LifeException("too big size of university");
    this->univercity.resize(weight_ * height_);
    std::fill(univercity.begin(), univercity.end(), false);
    this->neighbours.resize(weight_ * height_);
    std::fill(neighbours.begin(), neighbours.end(), 0);
    int x, y;
    while (!finput.eof()) {
        finput >> buffer;
        x = std::stoi(buffer);
        if (finput.eof()) {
            throw LifeException("Invalid format of file(only weight)");
        }
        finput >> buffer;
        y = std::stoi(buffer);
        this->at(x, y);
    }
}
