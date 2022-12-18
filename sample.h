//
// Created by User on 10.12.2022.
//
#pragma once

#include <array>
const unsigned int bytesPerSample = 2;
const int bytesPerSample_int = 2;
class sample
{
public:
    explicit sample();
    void intToSample(int);

    int sampleToInt();
    void setSample(char &, char &);

    void getSample(char *);
private:
    char buffer_[bytesPerSample]{};

};
