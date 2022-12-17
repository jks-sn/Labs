//
// Created by User on 17.12.2022.
//
#include "wav_input.h"
#include "wav_output.h"
#include <iostream>

void fillToEnd(wavRead &finput, wavWrite &foutput) {
    {
        std::string data;
        int nowPosition = finput.getPosition();
        finput.setFlagToEnd();
        int endPosition = finput.getPosition();
        finput.setFlagToPlace(nowPosition);
        finput.readSomeData(data, endPosition-nowPosition);
        foutput.writeSomeData(data, endPosition-nowPosition);
    }
}

int main() {
    std::string finput = "input.txt";
    std::string foutput = "output.txt";
    wavRead input(finput);
    wavWrite output(foutput);
    fillToEnd(input, output);
    return 0;
}