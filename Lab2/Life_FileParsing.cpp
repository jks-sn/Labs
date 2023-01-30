//
// Created by User on 24.11.2022.
//
#include "Life_FileParsing.h"

namespace life {
    void Life::FileParsing(std::ifstream &finput) {
        std::string buffer;
        getGameVersion(finput, buffer);
        getNameUniverce(finput, buffer, *(this));
        getRulesUniverse(finput, buffer, *(this));
        getWeightAndHeight(finput, buffer, (*this));
        this->univercity.resize(weight_ * height_);
        std::fill(univercity.begin(), univercity.end(), false);
        this->neighbours.resize(weight_ * height_);
        std::fill(neighbours.begin(), neighbours.end(), false);
        getAliveCell(finput, buffer, (*this));
    }
}