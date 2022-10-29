//
// Created by User on 10.10.2022.
//

#include "Life_Core.h"

int mod(const int x, const int y) {
    return (x == -1 ? y - 1 : x % y); //обёртка обработки x or y = -1 && x = weight+1; y = height+1
}

Life::Life() {
}

Life::Life(std::ifstream &finput) {
    std::fill(when_birth.begin(), when_birth.end(), false);
    std::fill(when_survival.begin(), when_survival.end(), false);
    std::string buffer;
    std::getline(finput, buffer);
    if (buffer != "#Life 1.06") {
        throw LifeException("Invalid format of file(first line)");
    }
    finput >> buffer;
    if (buffer != "#N") {
        throw LifeException("Invalid format of file(second line)");
    }
    std::getline(finput, this->name);
    finput >> buffer;
    if (buffer != "#R")
        throw LifeException("Invalid format of file(third line1)");
    finput >> buffer;
    if ((buffer.empty()) || (buffer[0] != 'B') || (buffer.find('/') == std::string::npos) ||
        ((buffer.find('/') + 1) == buffer.size()) || (buffer[(buffer.find('/') + 1)] != 'S'))
        throw LifeException("Invalid format of file(third line2)");
    for (size_t i = 1; i < buffer.find('/'); ++i) {
        if (!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line3");
        when_birth[static_cast <size_t>(buffer[i] - '0')] = true;
    }
    for (size_t i = (buffer.find('S') + 1); i < buffer.size(); ++i) {
        if (!std::isdigit(buffer[i]))
            throw LifeException("Invalid formal of file(third line4");
        when_survival[static_cast <size_t>(buffer[i] - '0')] = true;
    }
    finput >> buffer; //начали считывать размеер поля
    if (finput.eof())
        throw LifeException("Invalid format of file(no size of univercity(weight)");
    weight_ = std::stoul(buffer);
    finput >> buffer;
    if (finput.eof())
        throw LifeException("Invalid format of file(no size of univercity)(height)");
    height_ = std::stoul(buffer);
    if(height_ > 50 || weight_ > 50)
        throw LifeException("too big size of university");
    this->univercity.resize(weight_ * height_);
    std::fill(univercity.begin(), univercity.end(), false);
    this->neighbours.resize(weight_ * height_);
    std::fill(neighbours.begin(), neighbours.end(), 0);
    int x, y;
    while (!finput.eof()) {
        finput >> buffer;
        x = std::stoi(buffer) ;
        if(x <= 0 || x>=weight_)
            throw LifeException("Invalid coordinates");
        x-=1;
        if (finput.eof()) {
            throw LifeException("Invalid format of file(only weight)");
        }
        finput >> buffer;
        y = std::stoi(buffer);
        if(y <= 0 ||  y >= height_)
            throw LifeException("Invalid coordinates");
        y-=1;
        univercity[weight_ * y + x] = true;
    }
    std::cout << "all is good" << std::endl;
}

void Life::at(long long x, long long y) {
    while (x <= 0)
        x += static_cast<long long>(weight_);
    while (y <= 0)
        y += static_cast<long long>(height_);
    if (x > weight_ || y > height_)
        univercity[weight_ * y + x] = true; //найти нормальный метод
}
void Life::RunLife(unsigned int index) {
    for(size_t i = 0 ; i < index;++i) {
        this->RecountNeigbours();
        this->RecheckLife();
    }
}
void Life::RecountNeigbours() {
    for (size_t i = 0; i < height_ * weight_; ++i)
        CountNeigbours(i);

}
void Life::RecheckLife() {
    for (int i = 0; i < height_ * weight_; ++i) {
        if(when_birth[neighbours[i]])
            univercity[i] = true;
        else if(!when_survival[neighbours[i]])
            univercity[i] = false;
    }
}
void Life::CountNeigbours(const size_t &index) {
    int x = index % weight_;
    int y = index / weight_;
    //std::cout<<mod((y - 1), height_) * weight_ + mod((x - 1), weight_)<<" "<<mod(y - 1, height_) * weight_ + mod(x, weight_)<<" "<<mod(y - 1, height_) * weight_ + mod((x + 1), weight_)<<" "<< mod(y, height_) * weight_ + mod((x - 1), weight_)<<" "<<mod(y, height_) * weight_ + mod(x, weight_)<<" "<<mod(y, height_)* weight_ + mod(x+1, weight_)<<" "<<mod(y + 1, height_) * weight_ + mod((x - 1), weight_)<<" "<<mod(y + 1, height_) * weight_ + mod(x, weight_)<<" "<<mod(y + 1, height_) * weight_ + mod((x + 1), weight_)<<std::endl;
    //std::cout<<univercity[mod((y - 1), height_) * weight_ + mod((x - 1), weight_)]<<" "<<univercity[mod(y - 1, height_) * weight_ + mod(x, weight_)]<<" "<<univercity[mod(y - 1, height_) * weight_ + mod((x + 1), weight_)]<<" "<< univercity[mod(y, height_) * weight_ + mod((x - 1), weight_)]<<" "<<univercity[mod(y, height_) * weight_ + mod(x, weight_)]<<" "<<univercity[mod(y, height_)* weight_ + mod(x+1, weight_)]<<" "<<univercity[mod(y + 1, height_) * weight_ + mod((x - 1), weight_)]<<" "<<univercity[mod(y + 1, height_) * weight_ + mod(x, weight_)]<<" "<<univercity[mod(y + 1, height_) * weight_ + mod((x + 1), weight_)]<<std::endl;
    neighbours[index] = univercity[mod((y - 1), height_) * weight_ + mod((x - 1), weight_)] +
            univercity[mod(y - 1, height_) * weight_ + mod(x, weight_)] +
            univercity[mod(y - 1, height_) * weight_ + mod((x + 1), weight_)] +
            univercity[mod(y, height_) * weight_ + mod((x - 1), weight_)] +
            univercity[mod(y, height_)* weight_ + mod(x+1, weight_)] +
            univercity[mod(y + 1, height_) * weight_ + mod((x - 1), weight_)] +
            univercity[mod(y + 1, height_) * weight_ + mod(x, weight_)] +
            univercity[mod(y + 1, height_) * weight_ + mod((x + 1), weight_)];
}
void Life::PrintBoard() {
    for (int i = 0; i < height_ * weight_; ++i) {
        if (i % weight_ == 0 && i != 0)
            std::cout << std::endl;
        std::cout << univercity[i]<<" ";
    }
    std::cout << std::endl;
}

void Life::PrintBoard(std::ofstream &foutput) {
    for (int i = 0; i < height_ * weight_; ++i) {
        if (i % weight_ == 0 && i != 0)
            foutput << std::endl;
        foutput << univercity[i] << " ";
    }
    foutput<<std::endl;
}
