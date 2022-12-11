#include <iostream>
#include <sstream>
int main(){
    std::stringstream aba;
    aba << "35"<<" " <<"46"<<" "<< 57;
    int x,y,z,h;
    aba >>x;
    aba >>y;
    aba >>z;
    std::cout<<x<<" "<<y<<" "<<z;
    return 0;
};