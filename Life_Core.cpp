//
// Created by User on 10.10.2022.
//

#include "Life_Core.h"

int mod(const int x, const int y) {
    return (x == -1 ? y - 1 : x % y); //обёртка обработки x or y = -1 && x = weight+1; y = height+1
}
Life::Life(std::ifstream &finput) {
    std::fill(when_birth.begin(), when_birth.end(), false);
    std::fill(when_survival.begin(), when_survival.end(), false);
    this->FileParsing(finput);
}
Life::Life(const std::vector<bool>& univercity_, size_t weight, size_t height):weight_(weight),height_(height),univercity(univercity_) {
    this->neighbours.resize(this->weight_ * this->height_);
    std::fill(this->neighbours.begin(), this->neighbours.end(), 0);
}
Life::Life(const std::vector<bool>& univercity_,std::array<bool, 9> when_survival_,std::array<bool, 9> when_birth_, size_t weight, size_t height):weight_(weight),height_(height),when_birth(when_birth_),when_survival(when_survival_),univercity(univercity_) {
    this->neighbours.resize(this->weight_ * this->height_);
    std::fill(this->neighbours.begin(), this->neighbours.end(), 0);
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
void Life::getNeighbours(std::stringstream &soutput)
{
    for(const auto &i:this->neighbours)
        soutput <<i;
}
void Life::PrintBoard(std::stringstream &soutput)
{
    for(const auto &i:this->univercity)
        soutput <<i;
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
