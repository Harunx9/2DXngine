#include "Shader.h"
#include "../../Utils/File.h"
#include <vector>

Shader::Shader(const char * path, ShaderType type) :
    _path(path),
    _type(type),
    _compiled(false)
{
}

Shader::Shader(std::string source, ShaderType type) :
    _source(source),
    _type(type),
    _compiled(false)
{
}


Shader::~Shader()
{
    if (_compiled)
        glDeleteShader(this->_shaderId);
}

bool Shader::tryLoad()
{
    if (this->_source.empty() == false)
        return true;

    if (File::exist(this->_path))
    {
        this->_source = File::readFileToEnd(this->_path);
        return true;
    }

    return false;
}

ShaderCompileResult Shader::compile()
{
    this->_shaderId = glCreateShader(this->_type);
    const GLchar* src = this->_source.c_str();
    
    glShaderSource(this->_shaderId, 1, &src, nullptr);
    glCompileShader(this->_shaderId);
    
    _compiled = true;

    GLint success;
    glGetShaderiv(this->_shaderId, GL_COMPILE_STATUS, &success);

    //TODO: log error to game console if exist
    if (success == GL_FALSE)
        return ShaderCompileResult::COMPILATION_ERROR;

    return ShaderCompileResult::COMPILATION_SUCESS;
}