#include "Life_Core.h"
#include "Life_Interface.h"
int main(int argc, char*argv[]) {
    interface_online onlineInterface;
    interface_offline offlineInterface;
    if(argc == 1 || argc == 2)
    {
            onlineInterface.interface_(argc, argv);
    }
    else if(argc == 6)
    {
        try {
            offlineInterface.interface_(argc, argv);
        }
        catch(LifeException &exception){
            std::cerr << exception.what()<<std::endl;
        }
    }
    else
    {
        std::cout<<"wrong format of arguments of game"<<std::endl;
    }
    std::cout<<"All is very good";
}
