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

    class converter {
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
    };

    class mute : public converter {
    public:
            static const std::string name;
    private:
        void do_something(std::string &, std::string &, std::vector<std::string> &) override;
    };

    class mix : public converter {
    public:
        static const std::string name;
    private:
        void readANDmixANDwriteSecond(WavRead &, WavRead &, WavWrite &);

        void do_something(std::string &, std::string &, std::vector<std::string> &) override;

        void mixSecond(Sample *input1, Sample *input2);
    };

    class add : public converter {
    public:
        static const  std::string name;
    private:
        void do_add(WavRead &, WavRead &, WavWrite &, std::vector<std::string> &);

        void do_something(std::string &, std::string &, std::vector<std::string> &) override;
    };
    const std::string mute::name = "mute";
    const std::string mix::name = "mix";
    const std::string add::name = "add";
}