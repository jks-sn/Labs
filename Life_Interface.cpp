//
// Created by User on 24.10.2022.
//

#include "Life_Interface.h"
#include "Life_Core.h"

bool interface_online::type_interface(int argc) {
    return (argc == 2 || argc == 1);
}

void interface_online::interface_(int argc, char *argv[]) {
    std::string finput_path;
    std::ifstream finput;
    if (argc == 1) {
        finput_path = "example_1.txt";
    } else
        finput_path = argv[1];
    finput.open(finput_path);
    if (!finput.is_open())
        throw LifeException("No input file");
    //
    Life life(finput);
    system("CLS");
    life.PrintBoard();
    while (true) {
        std::string string;
        std::cout << "Enter the command:";
        std::cin >> string;
        if (string == "exit") {
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
            }
        } else if (string == "help") {
            std::cout << "4 supported commands: help; dump filename; tick x; exit" << std::endl;
        } else {
            std::cout << "This command don't support, write help to show context action" << std::endl;
        }
    }
}
