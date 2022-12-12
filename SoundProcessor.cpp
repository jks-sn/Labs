//
// Created by User on 11.12.2022.
//

#include "SoundProcessor.h"
void fileCopy(std::string finput, std::string foutput){
    wawRead wawRead_(finput);
    wawWrite wawWrite_(foutput);
    while (true){
        std::string buffer =wawRead_.readSomeData(1024);
        wawWrite_.writeSomeData(const_cast<char *>(buffer.c_str()), 1024);
        if (wawRead_.isFileEnd()){
            break;
        }
    }
};
void SoundProcessor::start(std::string &config_file_, std::string &output_file_,
                           std::vector<std::string>& input_files_) {
    try {
        std::string buffer;
        std::string buffer_waw = "buffer.waw";
        converters_factory factory;
        config fconfig(config_file_);
        while (true) {
            buffer = fconfig.getConvert();
            converter* converter_current = factory.converter_create(buffer);
            converter_current->do_something(buffer,input_files_[1],fconfig.readArgumentConvert());

        }
    }
    catch (const std::ifstream::failure& e){
        std::cerr << e.what();
    }
}