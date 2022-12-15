//
// Created by User on 14.12.2022.
//
#include "converters.h"
const size_t blockForReadHeader = 10000;
const size_t blockForReadSomeData = 1024;
void converter::jump(wavRead &infile, wavWrite &outfile, int seconds) {
    std::string data;
    infile.readSomeData(data,seconds * FREQ * bytesPerSample);
    outfile.writeSomeData(data, seconds * FREQ * bytesPerSample);
}
/*int find(const char*data,int data_size,const char*key,int key_size)
{
    int pos_search = 0;
    int pos_text = 0;
    for (pos_text = 0; pos_text < data_size - key_size;++pos_text)
    {
        if(data[pos_text] == key[pos_search])
        {
            ++pos_search;
            if(pos_search == key_size)
            {
                return (pos_text-key_size+1);
            }
        }
        else
        {
            pos_text -=pos_search;
            pos_search = 0;
        }
    }
    return -1;
}*/
void converter::writeAndReadHeader(wavRead &finput, wavWrite &foutput) {
    std::string data;
    size_t index_data;
    finput.readSomeData(data,blockForReadHeader);
    index_data = data.find("data")+4;
    if(index_data == data.npos)
        throw std::invalid_argument("Error, this is not .wav file");
    data.erase(index_data);
    finput.setFlagToPlace(index_data);
    //finput.readSomeData(data,index_data);
    foutput.writeSomeData(data,index_data);
}

void converter::fillToEnd(wavRead &finput, wavWrite &foutput) {
    while (!finput.isFileEnd()) {
        std::string data;
        finput.readSomeData(data,blockForReadSomeData);
        foutput.writeSomeData(data, blockForReadSomeData);
    }
}
