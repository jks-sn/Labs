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
        std::getline(std::cin,buffer);
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
    unsigned int index_;
    life.PrintBoard();
    while (true) {
        std::size_t pos;
        std::string string;
        std::cout << "Enter the command:";
        std::getline(std::cin,string);
        if (string == "exit") {
            finput.close();
            break;
        } else if (string.find("tick") == 0) { //0 - начало строки
            string = string.substr(string.find("tick")+5);
            try {
                index_ = std::stoul(string,&pos);
                if(pos != string.size())
                    throw(std::invalid_argument(""));
                life.RunLife(index_);
                system("CLS");
                life.PrintBoard();
            }
            catch(std::invalid_argument &exception){
                std::cout<<"invalid number of ticks, please try enter command again"<<std::endl;
            }
        } else if (string.find("dump") == 0) {
            std::ofstream foutput;
            std::string foutput_path = string.substr(string.find("dump")+5);
            foutput.open(foutput_path);
            if (!foutput.is_open()) {
                std::cout << "Output file not found/wrong name of file, please try again" << std::endl;
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
