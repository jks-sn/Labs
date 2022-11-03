#include "Life_Core.h"
#include "Life_Interface.h"

int main() {
    interface_online onlineInterface;
    interface_offline offlineInterface;
    std::string buffer;
    std::cout << "Write number to choose game mode" << std::endl << "1: for online mod" << std::endl
              << "2: for offline mod"
              << std::endl;
    while(true) {
        std::getline(std::cin,buffer);
        if (buffer == "1") {
            try {
                onlineInterface.interface_();
            }
            catch (LifeException &exception) { std::cerr << exception.what() << std::endl; }
            break;
        } else if (buffer == "2") {
            try {
                offlineInterface.interface_();
            }
            catch (LifeException &exception) {
                std::cerr << exception.what() << std::endl;
            }
            break;
        }
        else {
            std::cout << "invalid number; please write again" << std::endl;
        }
    }
    return 0;
}
