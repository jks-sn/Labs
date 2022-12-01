//
// Created by User on 27.11.2022.
//
#pragma once

#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

const unsigned int FREQ = 44100;
const unsigned int RIFF = 0x52494646;
const unsigned int WAVE = 0x57415645;
const unsigned int fmt = 0x666d7420;
const unsigned int subchunk1Size_PCM = 16;
const unsigned int WAVE_FORMAT_PCM = 0x0001;
const unsigned int DATA = 0x64617461
typedef struct Wav_header {
    unsigned int chunkId;
    unsigned long int chunckSize;
    unsigned int format;
    unsigned int subchunk1Id;
    unsigned long int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned long sampleRate;
    unsigned long byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    unsigned int subchunk2Id;
    unsigned long subchunk2Size;
} Wav_header;

class Wav {
public:
    explicit Wav(FILE*);

    Wav_header header;
    std::vector<unsigned char> data;
};
