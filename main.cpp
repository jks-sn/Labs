#include "Life_Core.h"
#include "Life_Interface.h"
int main(int argc, char*argv[]) {
    interface_online onlineInterface;
    onlineInterface.interface_(argc,argv);
    std::cout<<"All is very good";
    return 0;
}
