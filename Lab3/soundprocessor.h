//
// Created by User on 11.12.2022.
//
#pragma once

#include <vector>
#include <stdexcept>
#include <sstream>
#include "converters_factory.h"
#include "wav_input.h"
#include "wav_output.h"
#include "config.h"

namespace wavSoundProcessor {
    class WavException : public std::exception {
    public:
        explicit WavException(std::string &converter_type, std::vector<std::string> argmunets) : error_(
                std::move("Error,something got wrong with  " + converter_type+" ")) {
            for(auto i = argmunets.begin(); i < argmunets.end();++i)
                error_ += (*i)+" ";
        }
        const char *what() const noexcept override { return error_.c_str(); }

    private:
        std::string error_;
    };

    class SoundProcessor {
    public:
        static void start(std::string &config_file_, std::string &output_file_,
                          std::vector<std::string> &input_files_);
    };

}
