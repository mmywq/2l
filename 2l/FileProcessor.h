#pragma once
#include <string>

class FileProcessor {
public:
    static void processFile(const std::string& inputFilename, const std::string& outputFilename);
    static void processFileWithCustomException(const std::string& inputFilename, const std::string& outputFilename);
};