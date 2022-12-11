//
// Created by User on 11.12.2022.
//

#include "SoundProcessor.h"


SoundProcessor::SoundProcessor(std::string &config_file_, std::string &output_file_,
                               const std::vector<std::string> &input_files_){
    this->config_file.open(config_file_);
    if(!config_file.is_open())
        throw std::invalid_argument("not config file");
    this->output_file.open(output_file_);
    if(!output_file.is_open())
        throw std::invalid_argument("not output file");
    if (input_files.empty())
        throw
                std::invalid_argument("not input files");
    for(size_t i = 0; i < input_files.size();++i)
    {
        input_files[i].open(input_files_[i]);
        if(!input_files[i].is_open())
            throw std::invalid_argument("no one of input files");
    }
}

void SoundProcessor::start() {
    try {
        converters_factory factory;
        std::string line;
        while (std::getline(config_file, line)) {
            std::stringstream buffer; //regex?
            buffer<<line;
            converter* converter_current = factory.converter_create(line);
            buffer>>line;
            int x,y;
            buffer>>x;
            buffer>>y;
            if(buffer.rdbuf()->in_avail() == 0)
                throw std::invalid_argument("no first argument");
            buffer >>x;
            if(buffer.rdbuf()->in_avail() == 0)
                throw std::invalid_argument("no second argument");
            buffer>>y;
            std::vector<int> parametrs{x,y};
            converter_current->do_something(input_files[line.find('$')+1],output_file,parametrs);
        }
    }
    catch (const std::ifstream::failure& e){
        std::cerr << e.what();
    }
}