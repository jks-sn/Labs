//
// Created by User on 13.12.2022.
//
#pragma once
#include <fstream>
#include <string>
#include "sample.h"
#include <vector>
#include <iostream>
class config {
public:
    explicit config(std::string&);

    std::string getConvert();

    std::vector<std::string> readArgumentConvert();

    ~config();

private:
    std::ifstream config_;
};