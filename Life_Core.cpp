//
// Created by User on 10.10.2022.
//

#include "Life_Core.h"
Life::Life():height_(10),weight_(10),name("example universe") {
    when_survival = {false,false,true,false,false,false,false,false,false};
    when_birth = {false,true,true,false,false,false,false,false,false};
    std::fill(univercity.begin(),univercity.end(),false);
    this->at(0,2);
    this->at(1,0);
    this->at(1,2);
    this->at(2,1);
    this->at(2,2);
    std::fill(neighbours.begin(),neighbours.end(), 0);
}
Life::Life(std::ifstream &input) { //некритические ошибки?
    std::fill(univercity.begin(),univercity.end(),false);
    std::fill(when_birth.begin(),when_birth.end(),false);
    std::fill(when_survival.begin(),when_survival.end(),false);
    std::fill(neighbours.begin(),neighbours.end(), 0);
    std::string buffer;
    std::getline(input, buffer);
    if (buffer != "#Life 1.06") {
        throw LifeException("Invalid format of file(first line)");
    }
    input >> buffer;
    if (buffer != "#N") {
        throw LifeException("Invalid format of file(second line)");
    }
    std::getline(input,this->name);
    input>>buffer;
    if(buffer != "#R")
        throw LifeException("Invalid format of file(third line1)");
    input>>buffer;
    if((buffer.empty()) || (buffer[0] != 'B')||(buffer.find('/') == std::string::npos) || ((buffer.find('/') + 1) == buffer.size()) || (buffer[(buffer.find('/')+1)] != 'S'))
        throw LifeException("Invalid format of file(third line2)");
    for(size_t i = 1; i < buffer.find('/');++i)
    {
        if(!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line3");
        when_birth[static_cast <size_t>(buffer[i]-'0')] = true;
    }
    for(size_t i = (buffer.find('S')+1);i < buffer.size();++i){
        if(!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line4");
        when_survival[static_cast <size_t>(buffer[i]-'0')] = true;
    }
    input>>buffer; //начали считывать размеер поля
    if(input.eof())
        throw LifeException("Invalid format of file(no size of univercity(weight)");
    weight_ = std::stoul(buffer);
    input>>buffer;
    if(input.eof())
        throw LifeException("Invalid format of file(no size of univercity)(height)");
    height_ = std::stoul(buffer);
    this->univercity.resize(weight_*height_);
    int x,y;
    while(!input.eof()) {
        input>>buffer;
        x = std::stoi(buffer);
        if(input.eof())
        {
            throw LifeException("Invalid format of file(only weight)");
        }
        input>>buffer;
        y = std::stoi(buffer);
        this->at(x,y);
    }
    std::cout<<"all is good"<<std::endl;
}

void Life::at(long long &x, long long &y) {
    while(x < 0)
        x += static_cast<long long>(weight_);
    while(y < 0)
        y += static_cast<long long>(height_);
    if(x > weight_ || y > height_)
        univercity[univercity.cbegin(),weight_*y+x] = true; //найти нормальный метод
}

void Life::CheckNeigbours() {
    for(size_t i = 0; i < height_*weight_;++i)
    {}
}

unsigned char Life::SummNeigbours(const size_t &index) {
    int x = index % weight_;
    int y = index / weight_;
    return (univercity[(y-1)*weight+(x-1)*weight_]);
}

