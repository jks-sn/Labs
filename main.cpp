//
// Created by User on 17.12.2022.
//
#include "wav_input.h"
#include "wav_output.h"
#include <iostream>
#include <algorithm>
#include <iterator>
void readANDwriteSomeData(wavRead &infile, wavWrite &outfile, size_t size)
{
    std::vector<char> buffer_( size );
    infile.finput.read(buffer_.data(), size);
    outfile.foutput.write(buffer_.data(),size);
};

void writeAndReadHeader(wavRead &infile, wavWrite &outfile) {
    std::vector<char> buffer(10000);
    infile.finput.read(buffer.data(), 10000);
    std::vector<char>::iterator index_data;
    for(index_data = buffer.begin();index_data < buffer.end()-3;++index_data) {
        if (*index_data == 'd' && *(index_data + 1) == 'a' && *(index_data + 2) == 't' && *(index_data + 3) == 'a')
            break;
    }
    if(index_data == buffer.end()-3)
        throw std::invalid_argument("Error, this is not .wav file");
    infile.setFlagToPlace(0);
    readANDwriteSomeData(infile,outfile, index_data-buffer.begin()+4);
}
void jump(wavRead &infile, wavWrite &outfile, int seconds) {
    readANDwriteSomeData(infile,outfile,seconds*44100*2);
}
void fillToEnd(wavRead &finput, wavWrite &foutput) {
        int nowPosition = finput.getPosition();
        finput.setFlagToEnd();
        int endPosition = finput.getPosition();
        finput.setFlagToPlace(nowPosition);
        readANDwriteSomeData(finput,foutput, endPosition-nowPosition);

}

int main() {
    std::string finput = "input.wav";
    std::string foutput = "output.wav";
    wavRead input(finput);
    wavWrite output(foutput);
    writeAndReadHeader(input,output);
    fillToEnd(input,output);
    return 0;
}