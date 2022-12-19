//
// Created by User on 14.12.2022.
//
#include "converters.h"
const size_t blockForReadHeader = 10000;
const size_t blockForReadSomeData = 1024;
const size_t sizeOfWORDdata = 4;
const size_t indexOfBeginFile = 0;
void converter::jump(wavRead &infile, wavWrite &outfile, int seconds) {
    readANDwriteSomeData(infile,outfile,seconds*FREQ*bytesPerSample);
}
void converter::jump(wavRead &infile, int seconds) {
    std::vector<char> buffer_(seconds*FREQ*bytesPerSample);
    infile.finput.read(buffer_.data(), seconds*FREQ*bytesPerSample);
}
void converter::readHeader(wavRead &infile)
{
    std::vector<char> buffer(blockForReadHeader);
    infile.finput.read(buffer.data(), blockForReadHeader);
    std::vector<char>::iterator index_data;
    for(index_data = buffer.begin();index_data < buffer.end()-3;++index_data) {
        if (*index_data == 'd' && *(index_data + 1) == 'a' && *(index_data + 2) == 't' && *(index_data + 3) == 'a')
            break;
    }
    if(index_data == buffer.end()-3)
        throw std::invalid_argument("Error, this is not .wav file");
    infile.setFlagToPlace(index_data-buffer.begin()+4);
}
void converter::readANDwriteSomeData(wavRead &infile, wavWrite &outfile, size_t size)
{
    std::vector<char> buffer_( size );
    infile.finput.read(buffer_.data(), size);
    outfile.foutput.write(buffer_.data(),size);
};
void converter::writeAndReadHeader(wavRead &infile, wavWrite &outfile) {
    std::vector<char> buffer(blockForReadHeader);
    infile.finput.read(buffer.data(), blockForReadHeader);
    std::vector<char>::iterator index_data;
    for(index_data = buffer.begin();index_data < buffer.end()-3;++index_data) {
        if (*index_data == 'd' && *(index_data + 1) == 'a' && *(index_data + 2) == 't' && *(index_data + 3) == 'a')
            break;
    }
    if(index_data == buffer.end()-3)
        throw std::invalid_argument("Error, this is not .wav file");
    infile.setFlagToPlace(indexOfBeginFile);
    readANDwriteSomeData(infile,outfile, index_data-buffer.begin()+sizeOfWORDdata);
}
void converter::copy_file(std::string& name1, std::string& name2)
{
    wavRead in(name1);
    wavWrite out(name2);
    fillToEnd(in,out);
}
void converter::fillToEnd(wavRead &infile, wavWrite &outfile) {
        int nowPosition = infile.getPosition();
        infile.setFlagToEnd();
        int endPosition = infile.getPosition();
        infile.setFlagToPlace(nowPosition);
        readANDwriteSomeData(infile,outfile, endPosition-nowPosition);
}

int converter::minLength2Files(wavRead &inputFile, wavRead &inputFile1) {
    int input_now = inputFile.getPosition();
    int input1_now = inputFile1.getPosition();
    int input_size = inputFile.getSizeFile();
    int input1_size = inputFile1.getSizeFile();
    int min_size = (std::min(input_size-input_now,input1_size-input1_now))/FREQ/bytesPerSample;
    return min_size;
}

std::string converter::getSecondFile(std::string &parametr) {
    if (parametr.find('$') == parametr.npos) {
        throw std::invalid_argument("error, no input file");
    }
    if(parametr[0] != '$')
        throw std::invalid_argument("Errior, wrong first argument for mix");
    std::string input_number = parametr.erase(0,1);
    int buffer = std::stoi(parametr);
    input_number = std::to_string(buffer);
    return("input" + input_number+ ".wav");
}
void mix::readANDmixANDwriteSecond(wavRead &inputFile, wavWrite &outputFile) {
    sample second1[FREQ];
    sample second2[FREQ];
    inputFile.readSecond(second1,FREQ);
    inputFile.readSecond(second2,FREQ);
    this->mixSecond(second1,second2);
    outputFile.writeSecond(second1,FREQ);
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
