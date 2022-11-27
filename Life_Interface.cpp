//
// Created by User on 25.11.2022.
//
#include "Life_Interface.h"

std::string interface::getNumberExample(std::string &buffer) {
    if (std::stoi(buffer) >= 1 && std::stoi(buffer) <= numberExampleUnivercity)
        return("example_" + buffer + ".txt");
    else
        return buffer;
}
void interface::getInputFile(std::ifstream &finput) {
    std::string buffer;
    std::string finput_path;
    while(true) {
        std::cout << "Write path to input file or number of example university" << std::endl;
        std::getline(std::cin,buffer);
        try{
            finput_path =  interface::getNumberExample(buffer);
        }
        catch(std::invalid_argument &exception){
            finput_path = buffer;
        }
        finput.open(finput_path);
        if (!finput.is_open())
            std::cout<<"No such file, please try again"<<std::endl;
        else
            break;
    }
}
