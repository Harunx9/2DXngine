#pragma once
#include <string>


class File
{
public:
    File() = delete;
    File(const File & other) = delete;
    ~File() = delete;

    static bool exist(const std::string& path);
    static std::string readFileToEnd(const std::string& path);
};

