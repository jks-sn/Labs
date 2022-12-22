//
// Created by User on 14.12.2022.
//
#include "converters.h"

const size_t blockForReadHeader = 10000;
const size_t blockForReadSomeData = 1024;
const size_t sizeOfWORDdata = 4;
const size_t indexOfBeginFile = 0;
const int MaxPosition = 3;
using namespace wavconverter;

void wavconverter::Converter::jump(WavRead &infile, WavWrite &outfile, int seconds) {
    readANDwriteSomeData(infile, outfile, seconds * FREQ * bytesPerSample);
}

void wavconverter::Converter::jump(WavRead &infile, int seconds) {
    std::vector<char> buffer_(seconds * FREQ * bytesPerSample);
    infile.finput.read(buffer_.data(), seconds * FREQ * bytesPerSample);
}

void wavconverter::Converter::readHeader(WavRead &infile) {
    std::vector<char> buffer(blockForReadHeader);
    infile.finput.read(buffer.data(), blockForReadHeader);
    std::vector<char>::iterator index_data;
    for (index_data = buffer.begin(); index_data <= buffer.end() - sizeOfWORDdata; ++index_data) {
        if (*index_data == 'd' && *(index_data + 1) == 'a' && *(index_data + 2) == 't' && *(index_data + 3) == 'a')
            break;
    }
    if (index_data == buffer.end() - sizeOfWORDdata + 1)
        throw std::invalid_argument("Error, this is not .wav file");
    infile.setFlagToPlace(index_data - buffer.begin() + sizeOfWORDdata);
}

void wavconverter::Converter::readANDwriteSomeData(WavRead &infile, WavWrite &outfile, size_t size) {
    std::vector<char> buffer_(size);
    infile.finput.read(buffer_.data(), size);
    outfile.foutput.write(buffer_.data(), size);
};

void wavconverter::Converter::writeAndReadHeader(WavRead &infile, WavWrite &outfile) {
    std::vector<char> buffer(blockForReadHeader);
    infile.finput.read(buffer.data(), blockForReadHeader);
    std::vector<char>::iterator index_data;
    for (index_data = buffer.begin(); index_data <= buffer.end() - sizeOfWORDdata; ++index_data) {
        if (*index_data == 'd' && *(index_data + 1) == 'a' && *(index_data + 2) == 't' && *(index_data + 3) == 'a')
            break;
    }
    if (index_data == buffer.end() - sizeOfWORDdata + 1)
        throw std::invalid_argument("Error, this is not .wav file");
    infile.setFlagToPlace(indexOfBeginFile);
    readANDwriteSomeData(infile, outfile, index_data - buffer.begin() + sizeOfWORDdata);
}

void wavconverter::Converter::copy_file(std::string &name1, std::string &name2) {
    WavRead in(name1);
    WavWrite out(name2);
    fillToEnd(in, out);
}

void wavconverter::Converter::fillToEnd(WavRead &infile, WavWrite &outfile) {
    int nowPosition = infile.getPosition();
    infile.setFlagToEnd();
    int endPosition = infile.getPosition();
    infile.setFlagToPlace(nowPosition);
    readANDwriteSomeData(infile, outfile, endPosition - nowPosition);
}

int wavconverter::Converter::minLength2Files(WavRead &inputFile, WavRead &inputFile1) {
    int input_now = inputFile.getPosition();
    int input1_now = inputFile1.getPosition();
    int input_size = inputFile.getSizeFile();
    int input1_size = inputFile1.getSizeFile();
    int min_size = (std::min(input_size - input_now, input1_size - input1_now)) / FREQ / bytesPerSample;
    return min_size;
}

std::string wavconverter::Converter::getSecondFile(std::string &parametr) {
    if (parametr.find('$') == parametr.npos) {
        throw std::invalid_argument("error, no input file");
    }
    if (parametr[0] != '$')
        throw std::invalid_argument("Errior, wrong first argument for mix");
    std::string input_number = parametr.erase(0, 1);
    int buffer = std::stoi(parametr);
    input_number = std::to_string(buffer);
    return ("input" + input_number + ".wav");
}


void wavconverter::Mix::mixSecond(Sample *input1, Sample *input2) {
    int buffer;
    for (size_t i = 0; i < FREQ; ++i) {
        buffer = (input1[i]).sampleToInt();
        buffer += (input2[i]).sampleToInt();
        buffer /= 2;
        (input1[i]).intToSample(buffer);
    }
}

void wavconverter::Mix::readANDmixANDwriteSecond(WavRead &inputFile, WavRead &inputFile1, WavWrite &outputFile) {
    Sample second1[FREQ];
    Sample second2[FREQ];
    inputFile.readSecond(second1, FREQ);
    inputFile1.readSecond(second2, FREQ);
    this->mixSecond(second1, second2);
    outputFile.writeSecond(second1, FREQ);
}

void wavconverter::Add::do_add(WavRead &inputFile, WavRead &inputFile1, WavWrite &outputFile,
                               std::vector<std::string> &parametrs) {
    int startPositionExport = std::stoi(parametrs[1]);
    int endPositionExport = std::stoi(parametrs[2]);
    int startPosition = std::stoi(parametrs[3]);
    writeAndReadHeader(inputFile, outputFile);
    jump(inputFile, outputFile, startPosition);
    inputFile1.setFlagToPlace(startPositionExport * FREQ * bytesPerSample);
    int input_now = inputFile.getPosition();
    int input_size = inputFile.getSizeFile();
    int min_size = std::min(input_size - input_now,
                            (endPositionExport - startPositionExport) * FREQ_int * bytesPerSample_int);
    readANDwriteSomeData(inputFile1, outputFile, min_size);
    inputFile.setFlagToPlace(input_now + min_size);
    if (!inputFile.isFileEnd())
        fillToEnd(inputFile, outputFile);
}
