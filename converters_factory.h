//
// Created by User on 10.12.2022.
//
#pragma once
#include "converters.h"
#include <algorithm>
#include <stdexcept>
class converters_factory
{
public:
    converter *converter_create(std::string &converter_type);
private:
    std::vector<std::string> converters = {"mute","mix"};
};

