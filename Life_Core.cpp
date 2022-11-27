//
// Created by User on 10.10.2022.
//

#include "Life_Core.h"

int mod(const int x, const int y) {
    return (x == -1 ? y - 1 : x % y); //обёртка обработки x or y = -1 && x = weight+1; y = height+1
}


void Life::at(long long x, long long y) {
    if (x < 1 || x > weight_)
        throw LifeException("Invalid coordinates(x)");
    if (y < 1 || y > height_)
        throw LifeException("Invalid coordinates(y)");
    univercity[weight_ * (y - 1) + (x - 1)] = true; //найти нормальный метод
}

void Life::RunLife(unsigned long int index) {
    for (size_t i = 0; i < index; ++i) {
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
        if (when_birth[neighbours[i]])
            univercity[i] = true;
        else if (!when_survival[neighbours[i]])
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
                        univercity[mod(y, height_) * weight_ + mod(x + 1, weight_)] +
                        univercity[mod(y + 1, height_) * weight_ + mod((x - 1), weight_)] +
                        univercity[mod(y + 1, height_) * weight_ + mod(x, weight_)] +
                        univercity[mod(y + 1, height_) * weight_ + mod((x + 1), weight_)];
}

void Life::PrintBoard() {
    for (int i = 0; i < height_ * weight_; ++i) {
        if (i % weight_ == 0 && i != 0)
            std::cout << std::endl;
        std::cout << univercity[i] << " ";
    }
    std::cout << std::endl;
}

void Life::PrintBoard(std::ofstream &foutput) {
    for (int i = 0; i < height_ * weight_; ++i) {
        if (i % weight_ == 0 && i != 0)
            foutput << std::endl;
        foutput << univercity[i] << " ";
    }
    foutput << std::endl;
}
