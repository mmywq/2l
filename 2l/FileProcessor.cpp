#include "FileProcessor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

void FileProcessor::processFile(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        throw runtime_error("Не удалось открыть файл для чтения: " + inputFilename);
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        throw runtime_error("Не удалось открыть файл для записи: " + outputFilename);
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream stream(line);
        string prevWord, currWord;

        bool hasPrevWord = false;
        while (stream >> currWord) {
            if (hasPrevWord) {
                outputFile << currWord << " " << prevWord << " ";
                hasPrevWord = false;
            }
            else {
                prevWord = currWord;
                hasPrevWord = true;
            }
        }

        if (hasPrevWord) {
            outputFile << prevWord << " ";
        }

        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();
}
