//
// Created by User on 25.11.2022.
//
#include "Life_Interface.h"

const std::string flag_online_interface = "1";
const std::string flag_offline_interface = "2";

std::string interface::getNumberExample(std::string &buffer) {
    if (std::stoi(buffer) >= 1 && std::stoi(buffer) <= numberExampleUnivercity)
        return ("example_" + buffer + ".txt");
    else
        return buffer;
}

void interface::getInputFile(std::ifstream &finput) {
    std::string buffer;
    std::string finput_path;
    while (true) {
        std::cout << "Write path to input file or number of example university" << std::endl;
        std::getline(std::cin, buffer);
        try {
            finput_path = interface::getNumberExample(buffer);
        }
        catch (std::invalid_argument &exception) {
            finput_path = buffer;
        }
        finput.open(finput_path);
        if (!finput.is_open())
            std::cout << "No such file, please try again" << std::endl;
        else
            break;
    }
}

void interface::startGame() {
    interface_online onlineInterface;
    interface_offline offlineInterface;

    std::string buffer;
    std::cout << "Write number to choose game mode" << std::endl << "1: for online mod" << std::endl
              << "2: for offline mod"
              << std::endl;
    while (true) {
        std::getline(std::cin, buffer);
        if (buffer == flag_online_interface) {
            try {
                onlineInterface.interface_();
            }
            catch (LifeException &exception) { std::cerr << exception.what() << std::endl; }
            break;
        } else if (buffer == flag_offline_interface) {
            try {
                offlineInterface.interface_();
            }
            catch (LifeException &exception) {
                std::cerr << exception.what() << std::endl;
            }
            break;
        } else {
            std::cout << "invalid number; please write again" << std::endl;
        }
    }
}
