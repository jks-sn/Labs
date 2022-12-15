//
// Created by User on 10.12.2022.
//

#include "converters.h"

void mute::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    wavRead finput(input);
    wavWrite foutput(output);
    sample buffer[44100];
    sample zerobuffer[44100] = {0};
    writeAndReadHeader(finput, foutput);
    jump(finput, foutput, stoi(parametrs[0]));
    int delta = std::stoi(parametrs[1]) - std::stoi(parametrs[0]);
    while (delta && (!finput.isFileEnd()) ){
        finput.readSecond(buffer, 44100);
        --delta;
        foutput.writeSecond(zerobuffer, 44100);
    }
    fillToEnd(finput, foutput);
}

void mix::mixSecond(sample *input1, sample *input2) {
    long long int buffer;
    for (size_t i = 0; i < 44100; ++i) {
        buffer = this->sampleToInt(input1[i]);
        buffer += this->sampleToInt(input2[i]);
        buffer /= 2;
        this->intToSample(static_cast<int>(buffer), &input1[i]);
    }
}

void mix::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    if (parametrs[0].find('$') == parametrs[0].npos) {
        throw std::invalid_argument("error, no input file");
    }
    finput = "input" + parametrs[parametrs[0].find('$') + 1] + ".wav";
    wavRead inputFile(input);
    wavRead inputFile2(finput);
    wavWrite outputFile(output);
    int startPosition = std::stoi(parametrs[1]);
    writeAndReadHeader(inputFile, outputFile);
    while (std::strcmp((inputFile2.readFourBytes()).c_str(), "data") != 0) {
        if (inputFile2.isFileEnd())
            throw std::invalid_argument("Error, input2 file not .wav");
    }
    jump(inputFile, outputFile, startPosition);
    while (!(inputFile.isFileEnd() && inputFile2.isFileEnd()))
    {
        sample second1[44100];
        sample second2[44100];
        inputFile.readSecond(second1,44100);
        inputFile.readSecond(second2,44100);
        this->mixSecond(second1,second2);
        outputFile.writeSecond(second1,44100);
    }
    if(!inputFile.isFileEnd())
        fillToEnd(inputFile,outputFile);
}
