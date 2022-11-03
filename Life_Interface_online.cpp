//
// Created by User on 03.11.2022.
//
#include "Life_Interface.h"
void interface_online::interface_() {
    std::string buffer;
    std::string finput_path;
    std::ifstream finput;
    while(true) {
        std::cout << "Write path to input file or number of example university" << std::endl;
        std::cin >> buffer;
        try{
            if (std::stoi(buffer) >= 1 && std::stoi(buffer) <= numberExampleUnivercity) {
                finput_path = "example_" + buffer + ".txt";}
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
    Life life(finput);
    system("CLS");
    life.PrintBoard();
    while (true) {
        std::string string;
        std::cout << "Enter the command:";
        std::cin >> string;
        if (string == "exit") {
            finput.close();
            break;
        } else if (string == "tick") {
            std::cin >> string;
            life.RunLife(std::stoi(string));
            system("CLS");
            life.PrintBoard();
        } else if (string == "dump") {
            std::ofstream foutput;
            std::cin >> string;
            foutput.open(string);
            if (!foutput.is_open()) {
                std::cout << "Output file not found" << std::endl;
            } else {
                life.PrintBoard(foutput);
                foutput.close();
            }
        } else if (string == "help") {
            std::cout << "4 supported commands: help; dump filename; tick x; exit" << std::endl;
        } else {
            std::cout << "This command don't support, write help to show context action" << std::endl;
        }
    }
}
