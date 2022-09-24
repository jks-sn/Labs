//
// Created by User on 01.09.2022.
//
#include <iostream>
#include <ctime>
#include <cstddef> // size_t
#include "BigInt.hpp"

int main(int argc, char **argv) {
    BigInt test;
    BigInt test1(1000);
    BigInt test2(INT_MAX);
    test1+=test2;
    std::cout<< test1;
    return 0;
}
