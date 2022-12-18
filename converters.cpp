//
// Created by User on 10.12.2022.
//

#include "converters.h"

void mute::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    wavRead finput(input);
    wavWrite foutput(output);
    sample buffer[44100];
    sample zerobuffer[44100];
    writeAndReadHeader(finput, foutput);
    jump(finput, foutput, stoi(parametrs[0]));
    int delta = std::stoi(parametrs[1]) - std::stoi(parametrs[0]);
    while (delta && (!finput.isFileEnd()) ){
        finput.readSecond(buffer, FREQ);
        --delta;
        foutput.writeSecond(zerobuffer, FREQ);
    }
    fillToEnd(finput, foutput);
}

void mix::mixSecond(sample *input1, sample *input2) {
    int buffer;
    for (size_t i = 0; i < FREQ; ++i) {
        buffer = (input1[i]).sampleToInt();
        buffer += (input2[i]).sampleToInt();
        buffer /= 2;
        (input1[i]).intToSample(buffer);
    }
}
//переписать микс под новые знания
void mix::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    if (parametrs[0].find('$') == parametrs[0].npos) {
        throw std::invalid_argument("error, no input file");
    }
    if(parametrs[0][0] != '$')
        throw std::invalid_argument("Errior, wrong first argument for mix");
    std::string input_number = parametrs[0].erase(0,1);
    int buffer = std::stoi(parametrs[0]);
    input_number = std::to_string(buffer);
    finput = "input" + input_number+ ".wav";
    wavRead inputFile(input);
    wavRead inputFile1(finput);
    wavWrite outputFile(output);
    int startPosition = std::stoi(parametrs[1]);
    writeAndReadHeader(inputFile, outputFile);
    readHeader(inputFile1);
    jump(inputFile, outputFile, startPosition);
    int input_now = inputFile.getPosition();
    int input1_now = inputFile1.getPosition();
    int input_size = inputFile.getSizeFile();
    int input1_size = inputFile1.getSizeFile();
    int min_size = (std::min(input_size-input_now,input1_size-input1_now))/FREQ/bytesPerSample;
    for(size_t i = 0; i <min_size;++i)
    {
        sample second1[FREQ];
        sample second2[FREQ];
        inputFile.readSecond(second1,FREQ);
        inputFile.readSecond(second2,FREQ);
        this->mixSecond(second1,second2);
        outputFile.writeSecond(second1,FREQ);
    }
    if(!inputFile.isFileEnd())
        fillToEnd(inputFile,outputFile);
}

void add::do_something(std::string &input, std::string &output, std::vector<std::string> &parametrs) {
    std::string finput;
    if(parametrs.size() != 4)
        throw std::invalid_argument("error, wrong number of arguments for add");
    if (parametrs[0].find('$') == parametrs[0].npos) {
        throw std::invalid_argument("error, no input file");
    }
    if(parametrs[0][0] != '$')
        throw std::invalid_argument("Errior, wrong first argument for mix");
    std::string input_number = parametrs[0].erase(0,1);
    int buffer = std::stoi(parametrs[0]);
    input_number = std::to_string(buffer);
    finput = "input" + input_number+ ".wav";
    wavRead inputFile(input);
    wavRead inputFile1(finput);
    wavWrite outputFile(output);
    int startPositionExport = std::stoi(parametrs[1]);
    int endPositionExport = std::stoi(parametrs[2]);
    int startPosition = std::stoi(parametrs[3]);
    writeAndReadHeader(inputFile, outputFile);
    jump(inputFile,outputFile,startPosition);
    inputFile1.setFlagToPlace(startPositionExport*FREQ*bytesPerSample);
    int input_now = inputFile.getPosition();
    int input_size = inputFile.getSizeFile();
    int min_size = std::min(input_size-input_now,(endPositionExport-startPositionExport)*FREQ_int*bytesPerSample_int);
    readANDwriteSomeData(inputFile1,outputFile,min_size);
    inputFile.setFlagToPlace(input_now+min_size);
    if(!inputFile.isFileEnd())
        fillToEnd(inputFile,outputFile);
}
