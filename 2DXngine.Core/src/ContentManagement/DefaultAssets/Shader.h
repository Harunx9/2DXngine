#pragma once
#include <string>
#include <GL\glew.h>
#include "../../Utils/Macros/PropertyMacro.h"

enum ShaderType
{
    VERTEX_SHADER = GL_VERTEX_SHADER,
    FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
    GEOMERTY_SHADER = GL_GEOMETRY_SHADER
};

enum ShaderCompileResult
{
    COMPILATION_ERROR,
    COMPILATION_SUCESS
};

class Shader
{
public:
    Shader(const char * path, ShaderType type);
    Shader(std::string source, ShaderType type);
    ~Shader();
    
    bool tryLoad();
    ShaderCompileResult compile();
    READONLY_PROPERTY(GLuint, shaderId)
    READONLY_PROPERTY(ShaderType, type)
private:
    bool _compiled;
    std::string _source;
    std::string _path;
};

