//
// Created by User on 11.12.2022.
//

#include "SoundProcessor.h"

void fileCopy(std::string finput, std::string foutput) {
    wawRead wawRead_(finput);
    wawWrite wawWrite_(foutput);
    while (true) {
        std::string buffer = wawRead_.readSomeData(1024);
        wawWrite_.writeSomeData(buffer, 1024);
        if (wawRead_.isFileEnd()) {
            break;
        }
    }
};

void SoundProcessor::start(std::string &config_file_, std::string &output_file_,
                           std::vector<std::string> &input_files_) {
    try {
        std::string buffer;
        std::string buffer_waw = "buffer.waw";
        converters_factory factory;
        config fconfig(config_file_);
        fileCopy(input_files_[0], buffer);
        while (true) {
            buffer = fconfig.getConvert();
            if (buffer == "config_end")
                break;
            std::vector<std::string> abacaba = fconfig.readArgumentConvert();
            converter *converter_current = factory.converter_create(buffer);
            converter_current->do_something(buffer, output_file_, abacaba);
            fileCopy(output_file_, buffer);
        }
    }
    catch (const std::ifstream::failure &e) {
        std::cerr << e.what();
    }
}