#pragma once
#include "../Asset.h"
#include <string>
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "../../Utils/Macros/PropertyMacro.h"

enum ProgramCompilationResult
{
    COMPILE_ERROR,
    COMPILE_SUCCESS
};

class ShaderProgram : public Asset
{
public:
    static ShaderProgram* load(AssetPath assetPath);
    ShaderProgram(AssetPath assetPat);
    ShaderProgram(std::string vertexProgram, std::string fragmentProgram, std::string geometryProgram = "");
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

   
   READONLY_PROPERTY(GLuint, programId)
private:
    void loadShadersFromFile();
    void loadShadersFromSource(std::string vertexProgram, std::string fragmentProgram, std::string geometryProgram);
    std::string _programName;
    std::string _vertexPath;
    std::string _fragmentPath;
    std::string _geometryPath;
    Shader * _vertexShader;
    Shader * _fragmentShader;
    Shader * _geometryShader;
};

