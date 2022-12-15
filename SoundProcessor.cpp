//
// Created by User on 11.12.2022.
//

#include "SoundProcessor.h"

void copy_file(const std::string& name1, const std::string& name2)
{
     std::ifstream in(name1.c_str());
     std::ofstream out(name2.c_str());
     std::copy( std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(out));
}

void SoundProcessor::start(std::string &config_file_, std::string &output_file_,
                           std::vector<std::string> &input_files_) {
    try {
        std::string buffer;
        std::string buffer_wav = "buffer.wav";
        converters_factory factory;
        config fconfig(config_file_);
        copy_file(input_files_[0], buffer_wav);
        while (true) {
            buffer = fconfig.getConvert();
            if (buffer == "config_end")
                break;
            std::vector<std::string> arguments = fconfig.readArgumentConvert();
            converter *converter_current = factory.converter_create(buffer);
            converter_current->do_something(buffer_wav, output_file_, arguments);
            copy_file(output_file_, buffer_wav);
        }
    }
    catch (const std::ifstream::failure &e) {
        std::cerr << e.what()<<std::endl;
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}