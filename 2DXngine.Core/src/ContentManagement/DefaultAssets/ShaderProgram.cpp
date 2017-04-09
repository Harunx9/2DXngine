#include "ShaderProgram.h"



ShaderProgram::ShaderProgram(std::string programName) : Asset("/Shades/", DefaultAssetType::SHADER_PROGRAM_TYPE)
{
}

ShaderProgram * ShaderProgram::load(std::string programName)
{
    return nullptr;
}

ShaderProgram::~ShaderProgram()
{
}
