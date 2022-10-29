//
// Created by User on 24.10.2022.
//

#include "Life_Interface.h"
#include "Life_Core.h"

/*bool interface_online::type_interface(int &argc) {
    return (argc == 2 || argc == 1);
}*/

void interface_online::interface_(int &argc, char *argv[]) {
    std::string finput_path;
    std::ifstream finput;
    if (argc == 1) {
        finput_path = "example_1.txt";
    } else
        finput_path = argv[1];
    finput.open(finput_path);
    if (!finput.is_open())
        throw LifeException("No input file");
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
/*bool interface_offline::type_interface(int &argc) {
    return (argc == 6);
}*/

void interface_offline::interface_(int &argc,char *argv[]) {
    unsigned int iterations;
    std::string inpath = argv[1];
    std::ifstream finput;
    finput.open(inpath);
    if(!finput.is_open())
        throw LifeException("Wrong format of offline format:No input file");
    if (std::strcmp(argv[2], "-i") != 0) { throw LifeException("Wrong format of offline format: no iteration flag");}
    iterations = std::stoul(argv[3]);
    if (std::strcmp(argv[4], "-o") != 0) { throw LifeException("Wrong format of offline format: no output flag");}
    std::string outpath = argv[5];
    std::ofstream foutput;
    foutput.open(outpath);
    Life life;
    if(!foutput.is_open())
        throw LifeException("Wrong format of offline format:No output file");
    try {
        life = Life(finput);
    }
    catch(LifeException &exception){
        std::cerr << exception.what()<<std::endl;
        life = Life();
    }
    life.RunLife(iterations);
    life.PrintBoard(foutput);
    finput.close();
    foutput.close();
}
