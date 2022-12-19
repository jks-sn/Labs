#include "SoundProcessor.h"
int main(int argc, char*argv[])
{
    std::string config_file = argv[1];
    std::string output_file = argv[2];
    std::vector<std::string> files;
    for (int i = 3; i < argc; ++i) {
         files.emplace_back(argv[i]);
    }
    wavSoundProcessor::SoundProcessor::start(config_file, output_file, files);
}