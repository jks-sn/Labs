//
// Created by User on 10.12.2022.
//

#include "converters.h"
const int numberParametrsFORadd = 4;
using namespace wavconverter;

void wavconverter::mute::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    wavRead finput(input);
    wavWrite foutput(output);
    sample buffer[FREQ];
    sample zerobuffer[FREQ];
    writeAndReadHeader(finput, foutput);
    jump(finput, foutput, stoi(parametrs[0]));
    int delta = std::stoi(parametrs[1]) - std::stoi(parametrs[0]);
    while (delta && (!finput.isFileEnd())) {
        finput.readSecond(buffer, FREQ);
        --delta;
        foutput.writeSecond(zerobuffer, FREQ);
    }
    fillToEnd(finput, foutput);
}

//переписать микс под новые знания
void wavconverter::mix::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    try {
        finput = getSecondFile(parametrs[0]);
    }
    catch (std::exception &e) {
        std::cout << e.what();
        return;
    }
    wavRead inputFile(input);
    wavRead inputFile1(finput);
    wavWrite outputFile(output);
    int startPosition = std::stoi(parametrs[1]);
    writeAndReadHeader(inputFile, outputFile);
    readHeader(inputFile1);
    jump(inputFile, outputFile, startPosition);
    int min_size = minLength2Files(inputFile, inputFile1);
    for (size_t i = 0; i < min_size; ++i) {
        readANDmixANDwriteSecond(inputFile,inputFile1, outputFile);
    }
    if (!inputFile.isFileEnd())
        fillToEnd(inputFile, outputFile);
}


void wavconverter::add::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    if (parametrs.size() != numberParametrsFORadd)
        throw std::invalid_argument("error, wrong number of arguments for add");
    finput = getSecondFile(parametrs[0]);
    wavRead inputFile(input);
    wavRead inputFile1(finput);
    wavWrite outputFile(output);
    try {
        do_add(inputFile, inputFile1, outputFile, parametrs);
    }
    catch (std::exception &e) {
        std::cout << e.what();
        return;
    }
}
