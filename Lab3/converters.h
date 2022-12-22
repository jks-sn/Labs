//
// Created by User on 10.12.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include "wav_output.h"
#include "wav_input.h"
#include "sample.h"

namespace wavconverter {
    const size_t FREQ = 44100;
    const int FREQ_int = 44100;

    class Converter {
    public:

        virtual void do_something(std::string &, std::string &, std::vector<std::string> &) = 0;

        void writeAndReadHeader(WavRead &, WavWrite &);

        void fillToEnd(WavRead &, WavWrite &);

        void jump(WavRead &, WavWrite &, int);

        void readANDwriteSomeData(WavRead &infile, WavWrite &outfile, size_t size);

        void copy_file(std::string &name1, std::string &name2);

        void readHeader(WavRead &infile);

        void jump(WavRead &infile, int seconds);

        int minLength2Files(WavRead &infile, WavRead &in1file);

        std::string getSecondFile(std::string &parametr);

        virtual unsigned int getNumberArguments() = 0;
    };

    class Mute : public Converter {
    public:
            static const std::string name;
        const unsigned int numberArgumentsForConverter = 2;
        unsigned int getNumberArguments()override {return numberArgumentsForConverter;}
    private:
        void do_something(std::string &, std::string &, std::vector<std::string> &) override;
    };

    class Mix : public Converter {
    public:
        static const std::string name;
        const unsigned int NumberArgumentsForConverter = 2;
        unsigned int getNumberArguments()override {return NumberArgumentsForConverter;}
    private:
        void readANDmixANDwriteSecond(WavRead &, WavRead &, WavWrite &);

        void do_something(std::string &, std::string &, std::vector<std::string> &) override;

        void mixSecond(Sample *input1, Sample *input2);
    };

    class Add : public Converter {
    public:
        static const  std::string name;
        const unsigned int NumberArgumentsForConverter = 4;
        unsigned int getNumberArguments()override {return NumberArgumentsForConverter;}
    private:
        void do_add(WavRead &, WavRead &, WavWrite &, std::vector<std::string> &);
        void do_something(std::string &, std::string &, std::vector<std::string> &) override;
    };
}