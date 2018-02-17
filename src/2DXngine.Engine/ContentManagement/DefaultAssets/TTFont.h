#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <map>
#include "Texture.h"
#include "../Asset.h"

// implementation inspiration
//https://learnopengl.com/#!In-Practice/Text-Rendering

class SpriteBatch;
struct Color;
class ShaderProgram;

enum GlyphState { EMPTY_GLYPH, FILL_GLYPH };

struct Glyph
{
    Texture* tex;
    glm::ivec2 bearing;
    glm::ivec2 advance;
    GlyphState state;
    
    static Glyph empty() 
    {
        Glyph glyph = {
            nullptr,
            glm::ivec2(0,0),
            glm::ivec2(0,0),
            EMPTY_GLYPH
        };

        return glyph;
    }
};

class TTFont :
    public Asset
{
public:
    TTFont(AssetPath path);
    ~TTFont();

    static TTFont* load(AssetPath path);

    const Glyph& operator[](GLchar index)
    {
        if (this->_characterMap.find(index) ==
            this->_characterMap.end())
        {
            return Glyph::empty();
        }
        return this->_characterMap[index];
    }

    void draw(SpriteBatch* batch, std::string text, glm::vec2 position, Color color, glm::mat4 camera);
    void draw(SpriteBatch* batch, std::string text, glm::vec2 position, float scale, Color color, glm::mat4 camera);
    void draw(SpriteBatch* batch, std::string text, glm::vec2 position, glm::vec2 scale, Color color, glm::mat4 camera);

private:
    std::map<GLchar, Glyph> _characterMap;
    ShaderProgram* _fontShader;
};