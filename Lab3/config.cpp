//
// Created by User on 13.12.2022.
//

#include "config.h"

using namespace wavconfig;

wavconfig::Config::Config(std::string &config_path) {
    config_.open(config_path);
    if (!config_.is_open()) {
        throw std::invalid_argument("Error, can't open config file");
    }
}

std::string wavconfig::Config::getConvert() {
    std::string buffer;
    while (config_ >> buffer) {
        if (buffer == "#") { //поддерка комментариев
            getline(config_, buffer);
        } else
            return buffer;
    }
    return MessageOfEndConfig;
}

std::vector<std::string> wavconfig::Config::readArgumentConvert(unsigned int number_arguments) {
    std::vector<std::string> arguments;
    std::string buffer;
    for (unsigned int i = 1; i <= number_arguments; ++i) {
        if (!(config_ >> buffer)) {
            throw std::invalid_argument("error, wrong number arguments of converter");
        }
        arguments.push_back(buffer);
    }
    return arguments;
}

wavconfig::Config::~Config() {
    config_.close();
}
