#include "File.h"
#include <iostream>
#include <sstream>
#include <fstream>

bool File::exist(const std::string& path)
{
    std::ifstream file(path);
    return file.good();
}

std::string File::readFileToEnd(const std::string& path)
{
    std::string fileContent = "";

    std::ifstream file(path);
    std::stringstream fileStream;
    fileStream << file.rdbuf();
    fileContent = fileStream.str();

    return fileContent;
}
