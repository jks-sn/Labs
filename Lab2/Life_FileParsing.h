//
// Created by User on 02.12.2022.
//
#pragma once

#include "Life_Core.h"

namespace life {
    const std::string game_version = "#Life 1.06";
    const std::string flag_name_univerce = "#N";
    const std::string flag_rules_life = "#R";
    const char flag_rule_birth = 'B';
    const char flag_rule_survival = 'S';
    const char separator_birth_survive = '/';

    void getGameVersion(std::ifstream &finput, std::string &buffer);
}
