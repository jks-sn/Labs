//
// Created by User on 27.11.2022.
//

#include "wav_class.h"
/*
Wav::Wav(FILE *finput) {
    size_t numread;
    numread = fread_s(&(this->header), sizeof(this->header), sizeof(this->header), 1, finput);
    if (ferror(finput) || numread != 1 || this->header.chunkId != RIFF || this->header.format != WAVE ||
        this->header.subchunk1Id != fmt || this->header.subchunk1Size != subchunk1Size_PCM || this->header.audioFormat != WAVE_FORMAT_PCM ||
        this->header.numChannels != 1 || this->header.sampleRate != FREQ || this->header.subchunk2Id != DATA)
        throw std::exception();

}*/

