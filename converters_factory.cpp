//
// Created by User on 10.12.2022.
//

#include "converters_factory.h"

converter *converters_factory::converter_create(std::string &converter_type) {
    switch (std::distance(this->converters.begin(),std::find(this->converters.begin(),this->converters.end(),converter_type))) {
        case mute_type: {
            return new mute;
        }
        case mix_type: {
            return new mix;
        }
        case add_type:{
            return new add;
        }
        default:
        {
            throw std::invalid_argument("error, our program not supported this converter");
        }
    }
}

