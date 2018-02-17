#pragma once
#include <string>

class Path
{
public:
    Path() = delete;
    Path(const Path &other) = delete;
    ~Path() = delete;
    
    static std::string normalize(std::string input);
};
