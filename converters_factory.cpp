//
// Created by User on 10.12.2022.
//

#include "converters_factory.h"

converter *converters_factory::converter_create(std::string &converter_type) {
    switch (std::distance(this->converters.begin(),std::find(this->converters.begin(),this->converters.end(),converter_type))) {
        case 0: {
            return new mute;
        }
        case 1: {
            return new mix;
        }
        default:
        {
            throw std::invalid_argument("error, our program not supported this converter");
        }
    }
}

