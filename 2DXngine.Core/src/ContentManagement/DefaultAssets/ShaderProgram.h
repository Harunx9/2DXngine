#pragma once
#include "../Asset.h"
#include <string>
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "Shader.h"

enum ProgramCompilationResult
{
    COMPILE_ERROR,
    COMPILE_SUCCESS
};

class ShaderProgram : public Asset
{
public:
    static ShaderProgram* load(std::string name);
    ShaderProgram(std::string programName);
    ~ShaderProgram();

    ShaderProgram & use();

    ProgramCompilationResult compile();

    void setFloatParam(const char* paramName, float value);
    void setIntParam(const char* paramName, int value);
    void setVec2fParam(const char* paramName, float x, float y);
    void setVec2fParam(const char* paramName, const glm::vec2 &value);
    void setVec3fParam(const char* paramName, float x, float y, float z);
    void setVec3fParam(const char* paramName, const glm::vec3 &value);
    void setVec4fParam(const char* paramName, float x, float y, float z, float w);
    void setVec4fParam(const char* paramName, const glm::vec4 &value);
    void setMatrix4Param(const char* paramName, const glm::mat4 &value);

    GLuint get_programId() const;
private:
    std::string _programName;
    GLuint _programId;
    std::string _vertexPath;
    std::string _fragmentPath;
    std::string _geometryPath;
};

