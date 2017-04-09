#pragma once
#include "../Asset.h"
#include <string>

class ShaderProgram : public Asset
{
public:
    static ShaderProgram* load(std::string programName);
    ~ShaderProgram();
private:
    ShaderProgram(std::string programName);
};

