//
// Created by User on 02.12.2022.
//

#include "Life_FileParsing.h"

namespace life {
    void getGameVersion(std::ifstream &finput, std::string &buffer) {
        std::getline(finput, buffer);
        if (buffer != game_version) {
            throw LifeException("Invalid format of file(first line)");
        }
    }

    void getNameUniverce(std::ifstream &finput, std::string &buffer, Life &life) {
        finput >> buffer;
        if (buffer != flag_name_univerce) {
            throw LifeException("Invalid format of file(second line)");
        }
        std::getline(finput, life.name);
    }

    void getRulesUniverse(std::ifstream &finput, std::string &buffer, Life &life) {
        finput >> buffer;
        if (buffer != flag_rules_life)
            throw LifeException("Invalid format of file(third line1)");
        finput >> buffer;
        if ((buffer.empty()) || (buffer[0] != flag_rule_birth) ||
            (buffer.find(separator_birth_survive) == std::string::npos) ||
            ((buffer.find(separator_birth_survive) + 1) == buffer.size()) ||
            (buffer[(buffer.find(separator_birth_survive) + 1)] != flag_rule_survival))
            throw LifeException("Invalid format of file(third line2)");
        for (size_t i = 1; i < buffer.find(separator_birth_survive); ++i) {
            if (!std::isdigit(buffer[i]))
                throw LifeException("Invalid formal of file(third line3");
            life.when_birth[static_cast <size_t>(buffer[i] - '0')] = true;
        }
        for (size_t i = (buffer.find(flag_rule_survival) + 1); i < buffer.size(); ++i) {
            if (!std::isdigit(buffer[i]))
                throw LifeException("Invalid formal of file(third line4");
            life.when_survival[static_cast <size_t>(buffer[i] - '0')] = true;
        }
    }

    void getWeightAndHeight(std::ifstream &finput, std::string &buffer, Life &life) {
        finput >> buffer; //начали считывать размеер поля
        if (finput.eof())
            throw LifeException("Invalid format of file(no size of univercity(weight)");
        life.weight_ = std::stoul(buffer);
        finput >> buffer;
        if (finput.eof())
            throw LifeException("Invalid format of file(no size of univercity)(height)");
        life.height_ = std::stoul(buffer);
        if (life.height_ > BiggestHeight || life.weight_ > BiggestWeight)
            throw LifeException("too big size of university");
    }

    void getAliveCell(std::ifstream &finput, std::string &buffer, Life &life) {
        int x, y;
        while (!finput.eof()) {
            finput >> buffer;
            x = std::stoi(buffer);
            if (finput.eof()) {
                throw LifeException("Invalid format of file(only weight)");
            }
            finput >> buffer;
            y = std::stoi(buffer);
            life.at(x, y);
        }
    }
}