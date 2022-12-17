//
// Created by User on 17.12.2022.
//
int main()
{
        void converter::fillToEnd(wavRead &finput, wavWrite &foutput) {
        while (!finput.isFileEnd()) {
            std::string data;
            finput.readSomeData(data,blockForReadSomeData);
            foutput.writeSomeData(data, blockForReadSomeData);
        }
    }
}