//
// Created by User on 04.11.2022.
//
#include "Life_Interface.h"
void interface_offline::interface_() {
    std::string buffer;
    std::string finput_path;
    std::ifstream finput;
    Life life;
    while(true) {
        std::cout << "Write path to input file or number of example university(from 1 to " <<numberExampleUnivercity<<"):"<< std::endl;
        std::getline(std::cin,buffer);
        try{
            if (std::stoi(buffer) >= 1 && std::stoi(buffer) <= numberExampleUnivercity) {
                finput_path = "example_" + buffer + ".txt";}
        }
        catch(std::invalid_argument &exception){
            finput_path = buffer;
        }
        finput.open(finput_path);
        if (!finput.is_open()) {
            std::cout << "No such file, please try again" << std::endl;
        }
        else
        {
            try {
                life = Life(finput);
                break;
            }
            catch (LifeException &exception) {
                std::cerr << exception.what() <<"Please try again" <<std::endl;
                finput.close();
            }
        }
    }
    unsigned int iterations;
    while(true)
    {
        std::size_t pos;
        std::cout << "number of iterations:" << std::endl;
        std::getline(std::cin,buffer);
        try {
            iterations = std::stoul(buffer,&pos);
            if(pos != buffer.size())
                throw(std::invalid_argument(""));
            break;
        }
        catch(std::invalid_argument &exception)
        {
            std::cout << "wrong number of iterations, please try again" << std::endl;
        }
    }
    std::string outpath;
    std::ofstream foutput;
    while(true)
    {
        std::cout << "Write path to output file:" << std::endl;
        std::getline(std::cin,outpath);
        foutput.open(outpath);
        if (!foutput.is_open())
            std::cout<<"No such file, please try again"<<std::endl;
        else
            break;
    }
    life.RunLife(iterations);
    life.PrintBoard(foutput);
    finput.close();
    foutput.close();
}
