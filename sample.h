//
// Created by User on 10.12.2022.
//
#pragma once

#include <array>
const unsigned int bytesPerSample = 2;
class sample
{
public:
    void intToSample(int);

    int sampleToInt();

private:
    char buffer_[bytesPerSample];
};
