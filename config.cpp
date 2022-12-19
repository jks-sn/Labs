//
// Created by User on 13.12.2022.
//

#include "config.h"
using namespace wavconfig;
wavconfig::config::config(std::string &config_path) {
    config_.open(config_path);
    if (!config_.is_open()) {
        throw std::invalid_argument("Error, can't open config file");
    }
}

std::string wavconfig::config::getConvert() {
    std::string buffer;
    while (config_ >> buffer) {
        if (buffer == "#") { //считать комментарий
            getline(config_, buffer);
        } else if (buffer == "mute" || buffer == "mix" || buffer == "add") {
            return buffer;
        }
    }
    return "config_end";
}

std::vector<std::string> wavconfig::config::readArgumentConvert(std::string &convert_type) {
    std::vector<std::string> arguments;
    std::string buffer;
    if (!(config_ >> buffer)) {
        throw std::invalid_argument("error, no argument 1 of converter");
    }
    arguments.push_back(buffer);
    if (!(config_ >> buffer)) {
        throw std::invalid_argument("error, no argument 2 of converter");
    }
    arguments.push_back(buffer);
    if (convert_type == "mix" || convert_type == "mute")
        return arguments;
    if (!(config_ >> buffer)) {
        throw std::invalid_argument("error, no argument 3 of converter");
    }
    arguments.push_back(buffer);
    if (!(config_ >> buffer)) {
        throw std::invalid_argument("error, no argument 4 of converter");
    }
    arguments.push_back(buffer);
/*    if((config_>>buffer))
    {
        arguments.push_back(buffer);
    }*/
    return arguments;
}

wavconfig::config::~config() {
    config_.close();
}
