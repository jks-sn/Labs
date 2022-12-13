//
// Created by User on 10.12.2022.
//

#include "converters.h"

void jump(wawRead &infile, wawWrite &outfile, int seconds) {
    std::string buffer = infile.readSomeData(seconds * 44100 * 2);
    outfile.writeSomeData(buffer, seconds * 44100 * 2);
}

void converter::writeAndReadHeader(wawRead &finput, wawWrite &foutput) {
    std::string buffer;
    do {
        buffer = finput.readHeader();
        foutput.writeHeader(buffer);
    } while (buffer != "data");
}

void fillToEnd(wawRead &finput, wawWrite &foutput) {
    std::string buffer;
    while (finput.isFileEnd()) {
        buffer = finput.readSomeData(1024);
        foutput.writeSomeData(buffer, 1024);
    }
}

void mute::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    wawRead finput(input);
    wawWrite foutput(output);
    sample buffer[44100];
    sample zerobuffer[44100] = {0};
    writeAndReadHeader(finput, foutput);
    jump(finput, foutput, stoi(parametrs[0]));
    int delta = std::stoi(parametrs[1]) - std::stoi(parametrs[0]);
    while (delta && finput.isFileEnd()) {
        finput.readSecond(buffer, 44100);
        --delta;
        foutput.writeSecond(zerobuffer, 44100);
    }
    fillToEnd(finput, foutput);
}

void mix::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {

}

