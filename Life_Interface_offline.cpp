//
// Created by User on 04.11.2022.
//
#include "Life_Interface.h"

void interface_offline::interface_() {
    std::ifstream finput;
    std::ofstream foutput;
    unsigned char iterations;
    this->getInputFile(finput);
    Life life(finput);
    iterations = this->getNumberIterations();
    this->getOutputFile(foutput);
    life.RunLife(iterations);
    life.PrintBoard(foutput);
    finput.close();
    foutput.close();
}

unsigned int interface_offline::iterationsFromStringToInt(std::string &buffer) {
    unsigned int iterations;
    std::size_t pos;
    iterations = std::stoul(buffer, &pos);
    if (pos != buffer.size())
        throw (std::invalid_argument(""));
    return iterations;
}

unsigned int interface_offline::getNumberIterations() {
    while (true) {
        unsigned int iterations;
        std::string buffer;
        std::cout << "number of iterations:" << std::endl;
        std::getline(std::cin, buffer);
        try {
            iterations = this->iterationsFromStringToInt(buffer);
            return iterations;
        }
        catch (std::invalid_argument &exception) {
            std::cout << "wrong number of iterations, please try again" << std::endl;
        }
    }
}

void interface_offline::getOutputFile(std::ofstream &foutput) {
    std::string outpath;
    while (true) {
        std::cout << "Write path to output file:" << std::endl;
        std::getline(std::cin, outpath);
        foutput.open(outpath);
        if (!foutput.is_open())
            std::cout << "No such file, please try again" << std::endl;
        else
            break;
    }
}


