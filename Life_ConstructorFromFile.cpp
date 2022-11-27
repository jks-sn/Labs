//
// Created by User on 03.11.2022.
//
#include "Life_Core.h"

Life::Life(std::ifstream &finput) {
    std::fill(when_birth.begin(), when_birth.end(), false);
    std::fill(when_survival.begin(), when_survival.end(), false);
    FileParsing(finput);
}
