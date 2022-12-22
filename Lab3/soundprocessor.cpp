//
// Created by User on 11.12.2022.
//

#include "soundprocessor.h"

using namespace wavSoundProcessor;
namespace wavSoundProcessor
{
    const std::string NameOfBuffer = "buffer.wav";
}
void wavSoundProcessor::SoundProcessor::start(std::string &config_file_, std::string &output_file_,
                                               std::vector<std::string> &input_files_) {
    try {
        std::string buffer;
        std::string buffer_wav = NameOfBuffer;
        wavconverter::converters_factory factory;
        wavconfig::Config fconfig(config_file_);
        wavconverter::Converter *converter_current;
        converter_current->copy_file(input_files_[0], buffer_wav);
        while (true) {
            buffer = fconfig.getConvert();
            if (buffer == wavconfig::MessageOfEndConfig)
                break;
            converter_current = factory.converter_create(buffer);
            std::vector<std::string> arguments = fconfig.readArgumentConvert(converter_current->getNumberArguments());
            converter_current->сhanger(buffer_wav, output_file_, arguments);
            converter_current->copy_file(output_file_, buffer_wav);
        }
    }
    catch (const std::ifstream::failure &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}