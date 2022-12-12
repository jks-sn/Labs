//
// Created by User on 10.12.2022.
//

#include "converters.h"
void jump(std::ifstream &input, std::ofstream &output, int seconds) {
    char buffer[44100*seconds];
    input.read(buffer,seconds*44100);
    output.write(buffer,seconds*44100);
}
void mute::do_something(std::string &input, std::string &output, std::vector<std::string>& parametrs) {
    jump(input,output,parametrs[0]);
}

void mix::do_something(std::string &input, std::string &output, std::vector<std::string>& parametrs) {

}
