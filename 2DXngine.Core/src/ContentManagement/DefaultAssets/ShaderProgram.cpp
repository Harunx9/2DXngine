#include "ShaderProgram.h"
#include <glm/gtc/type_ptr.hpp>
GLuint ShaderProgram::get_programId() const
{
    return this->_programId;
}

void ShaderProgram::loadShadersFromFile()
{
    this->_vertexShader = new Shader(this->_vertexPath.c_str(), ShaderType::VERTEX_SHADER);
    this->_fragmentShader = new Shader(this->_fragmentPath.c_str(), ShaderType::FRAGMENT_SHADER);
    this->_geometryShader = new Shader(this->_geometryPath.c_str(), ShaderType::GEOMERTY_SHADER);
}

void ShaderProgram::loadShadersFromSource(std::string vertexProgram, std::string fragmentProgram, std::string geometryProgram)
{
    this->_vertexShader = new Shader(vertexProgram, ShaderType::VERTEX_SHADER);
    this->_fragmentShader = new Shader(fragmentProgram, ShaderType::FRAGMENT_SHADER);
    this->_geometryShader = new Shader(geometryProgram, ShaderType::GEOMERTY_SHADER);
}

ProgramCompilationResult ShaderProgram::compile()
{
    ShaderCompileResult vertexCompileResult, fragmentCompileResult, geometryCompileResult = ShaderCompileResult::COMPILATION_ERROR;

    if (this->_vertexShader->tryLoad())
    {
        vertexCompileResult = this->_vertexShader->compile();
        if (vertexCompileResult == ShaderCompileResult::COMPILATION_ERROR)
            return ProgramCompilationResult::COMPILE_ERROR;
    }

    if (this->_fragmentShader->tryLoad())
    {
        fragmentCompileResult = this->_fragmentShader->compile();
        if (fragmentCompileResult == ShaderCompileResult::COMPILATION_ERROR)
            return ProgramCompilationResult::COMPILE_ERROR;
    }

    if (this->_geometryShader->tryLoad())
    {
        geometryCompileResult = this->_geometryShader->compile();
        if (geometryCompileResult == ShaderCompileResult::COMPILATION_ERROR) 
            return ProgramCompilationResult::COMPILE_ERROR;
    }

    this->_programId = glCreateProgram();

    if (vertexCompileResult == ShaderCompileResult::COMPILATION_SUCESS)
    {
        glAttachShader(this->_programId, this->_vertexShader->get_shaderId());
    }

    if (fragmentCompileResult == ShaderCompileResult::COMPILATION_SUCESS)
    {
        glAttachShader(this->_programId, this->_fragmentShader->get_shaderId());
    }

    if (geometryCompileResult == ShaderCompileResult::COMPILATION_SUCESS)
    {
        glAttachShader(this->_programId, this->_geometryShader->get_shaderId());
    }

    glLinkProgram(this->_programId);

    GLint success;
    glGetProgramiv(this->_programId, GL_LINK_STATUS, &success);

    delete this->_vertexShader;
    delete this->_fragmentShader;
    delete this->_geometryShader;

    if (success == GL_FALSE)
        return ProgramCompilationResult::COMPILE_ERROR;

    return ProgramCompilationResult::COMPILE_SUCCESS;
}

void ShaderProgram::setFloatParam(const char * paramName, float value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform1f(location, (GLfloat)value);
}

void ShaderProgram::setIntParam(const char * paramName, int value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform1i(location, (GLint)value);
}

void ShaderProgram::setVec2fParam(const char * paramName, float x, float y)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform2f(location, (GLfloat)x, (GLfloat)y);
}

void ShaderProgram::setVec2fParam(const char * paramName, const glm::vec2 & value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform2f(location, (GLfloat)value.x, (GLfloat)value.y);
}

void ShaderProgram::setVec3fParam(const char * paramName, float x, float y, float z)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform3f(location, (GLfloat)x, (GLfloat)y, (GLfloat)z);
}

void ShaderProgram::setVec3fParam(const char * paramName, const glm::vec3 & value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform3f(location, (GLfloat)value.x, (GLfloat)value.y, (GLfloat)value.z);
}

void ShaderProgram::setVec4fParam(const char * paramName, float x, float y, float z, float w)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform4f(location, (GLfloat)x, (GLfloat)y, (GLfloat)z, (GLfloat)w);
}

void ShaderProgram::setVec4fParam(const char * paramName, const glm::vec4 & value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniform4f(location, (GLfloat)value.x, (GLfloat)value.y, (GLfloat)value.z, (GLfloat)value.w);
}

void ShaderProgram::setMatrix4Param(const char * paramName, const glm::mat4 & value)
{
    GLint location = glGetUniformLocation(this->_programId, paramName);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

ShaderProgram::ShaderProgram(std::string programName) : Asset("Content/Shaders/", DefaultAssetType::SHADER_PROGRAM_TYPE)
{
    this->_programName;
    this->_vertexPath = this->get_path() + programName + "vertex.glsl";
    this->_fragmentPath = this->get_path() + programName + "fragment.glsl";
    this->_geometryPath = this->get_path() + programName + "geometry.glsl";
    loadShadersFromFile();
}

ShaderProgram::ShaderProgram(std::string vertexProgram, std::string fragmentProgram, std::string geometryProgram) :Asset("Content/Shaders/", DefaultAssetType::SHADER_PROGRAM_TYPE)
{
    loadShadersFromSource(vertexProgram, fragmentProgram, geometryProgram);
}

ShaderProgram * ShaderProgram::load(std::string name)
{
    auto program = new ShaderProgram(name);
    auto compileResult = program->compile();
    if (compileResult == ProgramCompilationResult::COMPILE_SUCCESS)
    {
        return program;
    }
    return nullptr;
}

ShaderProgram::~ShaderProgram()
{
}

ShaderProgram & ShaderProgram::use()
{
    glUseProgram(this->_programId);
    return *this;
}
