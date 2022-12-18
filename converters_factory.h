//
// Created by User on 10.12.2022.
//
#pragma once
#include "converters.h"
#include <algorithm>
#include <stdexcept>
enum converters_type{
    mute_type,
    mix_type,
    add_type
};
class converters_factory
{
public:
    converter *converter_create(std::string &converter_type);
private:
    std::vector<std::string> converters = {"mute","mix","add"};
};

