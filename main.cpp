//
// Created by User on 01.09.2022.
//
#include <iostream>
#include <ctime>
#include <cstddef> // size_t
#include "BigInt.hpp"

int main(int argc, char **argv) {
    BigInt test;
    BigInt test1(100);
    BigInt test11(100);
    test1*=test11;
    BigInt test2("-1");
    std::cout<< test1.data[0];
    return 0;
}
