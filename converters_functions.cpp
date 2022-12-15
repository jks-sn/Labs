//
// Created by User on 14.12.2022.
//
#include "converters.h"

int converter::sampleToInt(sample &sample_) {
    int buffer;
    if (sample_.buffer_[0] & (0x01 << 8)) {
        sample_.buffer_[0] = sample_.buffer_[0] & 0x7F;
        buffer = (static_cast<int>(sample_.buffer_[1]) << 8);
        buffer += sample_.buffer_[0];
        buffer = (~buffer) + 1;
    } else {
        buffer = (static_cast<int>(sample_.buffer_[1]) << 8);
        buffer += sample_.buffer_[0];
    }
    return buffer;
}

void converter::intToSample(int data, sample *sample_) {
    if (data > 0) {
        sample_->buffer_[1] = static_cast<char>(data);
        sample_->buffer_[0] = static_cast<char>(data >> 8);
    } else {
        data = (~data) + 1;
        sample_->buffer_[1] = static_cast<char>(data);
        sample_->buffer_[0] = static_cast<char>((data >> 8) | 128);
    }
}

void converter::jump(wavRead &infile, wavWrite &outfile, int seconds) {
    std::string data;
    infile.readSomeData(data,seconds * 44100 * 2);
    outfile.writeSomeData(data, seconds * 44100 * 2);
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
    finput.readSomeData(data,10000);
    index_data = data.find("data")+4;
    if(index_data == data.npos)
        throw std::invalid_argument("Error, this is not .wav file");
    finput.setFlagToStartFile();
    finput.readSomeData(data,index_data);
    foutput.writeSomeData(data,index_data);
}

void converter::fillToEnd(wavRead &finput, wavWrite &foutput) {
    std::string data;
    while (!finput.isFileEnd()) {
        finput.readSomeData(data,1024);
        foutput.writeSomeData(data, 1024);
    }
}
