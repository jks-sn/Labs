#include <utility>

#include "Life_Core.h"
int main() {
    std::ifstream file("C:\\Users\\User\\Documents\\GitHub\\Labs\\test.txt");
    if (!file.is_open()) {
        throw std::invalid_argument("file not opened");
    }
    Life life;
    try {
       life = Life(file);
    }
    catch (LifeException &exception)
    {
        std::cerr << exception.what()<<std::endl;
        life = Life();
    }
    return 0;
}
