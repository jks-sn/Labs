//
// Created by User on 01.09.2022.
//
#include <iostream>
#include <ctime>
#include <cstddef> // size_t
#include "BigInt.hpp"

int main(int argc, char **argv) {
    BigInt test;
    BigInt test1(0);
    BigInt test2(4);
    std::cout<<(test1 < test2);
    //std::cout<<(s == INT_MAX);
    //std::cout<<sizeof(bool);
    return 0;
}
