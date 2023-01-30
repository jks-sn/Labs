//
// Created by User on 10.12.2022.
//

#include "converters.h"

const int NumberParametrsFORadd = 4;
using namespace wavconverter;
const std::string wavconverter::Mute::name = "mute";
const std::string wavconverter::Mix::name = "mix";
const std::string wavconverter::Add::name = "add";
void wavconverter::Mute::changer(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    WavRead finput(input);
    WavWrite foutput(output);
    Sample buffer[FREQ];
    Sample zerobuffer[FREQ];
    writeAndReadHeader(finput, foutput);
    jump(finput, foutput, stoi(parametrs[0]));
    int delta = std::stoi(parametrs[1]) - std::stoi(parametrs[0]);
    if(delta < 0)
        throw std::invalid_argument("");
    while (delta && (!finput.isFileEnd())) {
        finput.readSecond(buffer, FREQ);
        --delta;
        foutput.writeSecond(zerobuffer, FREQ);
    }
    fillToEnd(finput, foutput);
}

void wavconverter::Mix::changer(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
        finput = getSecondFile(parametrs[0]);
        WavRead inputFile(input);
        WavRead inputFile1(finput);
        WavWrite outputFile(output);
        int startPosition = std::stoi(parametrs[1]);
        if(startPosition < 0)
            throw std::invalid_argument("");
        writeAndReadHeader(inputFile, outputFile);
        readHeader(inputFile1);
        jump(inputFile, outputFile, startPosition);
        int min_size = minLength2Files(inputFile, inputFile1);
        for (size_t i = 0; i < min_size; ++i) {
            readANDmixANDwriteSecond(inputFile, inputFile1, outputFile);
        }
        if (!inputFile.isFileEnd())
            fillToEnd(inputFile, outputFile);
}


void wavconverter::Add::changer(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    if (parametrs.size() != NumberParametrsFORadd)
        throw std::invalid_argument("");
    finput = getSecondFile(parametrs[0]);
    WavRead inputFile(input);
    WavRead inputFile1(finput);
    WavWrite outputFile(output);
        do_add(inputFile, inputFile1, outputFile, parametrs);
    }
