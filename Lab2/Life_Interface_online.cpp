//
// Created by User on 03.11.2022.
//
#include "Life_Interface.h"

void interface_online::interface_() {
    std::ifstream finput;
    this->getInputFile(finput);
    Life life(finput);
    system("CLS");
    unsigned int index_;
    life.PrintBoard();
    while (true) {
        std::size_t pos = 0;
        std::string string;
        std::cout << "Enter the command:";
        std::getline(std::cin, string);
        if (string == "exit") {
            finput.close();
            break;
        } else if (string.find("tick") == 0) { //0 - начало строки
            try {
                if(string.size() != 4) {
                    string = string.substr(string.find("tick") + 5);
                    index_ = std::stoul(string, &pos);
                    if ((pos != string.size()) || (index_>maxNumberTicks))
                        throw (std::invalid_argument(""));
                }
                else
                    index_  = 1;
                life.RunLife(index_);
                system("CLS");
                life.PrintBoard();
            }
            catch (std::invalid_argument &exception) {
                std::cout << "invalid number of ticks, please try enter command again" << std::endl;
            }
            catch(std::out_of_range &exception)
            {
                std::cout << "invalid number of ticks, please try enter command again" << std::endl;
            }
        } else if (string.find("dump") == 0) {
            try {
                std::ofstream foutput;
                if (string.size() == 4)
                    throw (std::invalid_argument(""));
                std::string foutput_path = string.substr(string.find("dump") + 5);
                foutput.open(foutput_path);
                if (!foutput.is_open()) {
                    std::cout << "Output file not found/wrong name of file, please try again" << std::endl;
                } else {
                    life.PrintBoard(foutput);
                    foutput.close();
                }
            }
            catch (std::invalid_argument &exception) {
                std::cout << "invalid dump arguments, please try enter command again" << std::endl;
            }
            catch(std::out_of_range &exception)
            {
                std::cout << "invalid dump arguments, please try enter command again" << std::endl;
            }
        } else if (string == "help") {
            std::cout << "4 supported commands: help; dump filename; tick x; exit" << std::endl;
        } else {
            std::cout << "This command don't support, write help to show context action" << std::endl;
        }
    }
}

