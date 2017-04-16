#pragma once
#include <string>
#include <GL\glew.h>

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
    GLuint get_shaderId() const;
    ShaderType get_type() const;


private:
    bool _compiled;
    std::string _source;
    std::string _path;
    GLuint _shaderId;
    ShaderType _type;
};

