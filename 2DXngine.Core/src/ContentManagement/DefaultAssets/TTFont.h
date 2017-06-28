#pragma once
#include "..\Asset.h"
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <map>

//https://learnopengl.com/#!In-Practice/Text-Rendering

enum GlyphState { EMPTY_GLYPH, FILL_GLYPH };

struct Glyph
{
    GLuint textureId;
    glm::ivec2 size;
    glm::ivec2 bearing;
    GLuint advance;
    GlyphState state;

    static Glyph empty() 
    {
        Glyph glyph = {
            0,
            glm::ivec2(0,0),
            glm::ivec2(0,0),
            0,
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

    Glyph& operator[](GLchar index)
    {
        if (this->_characterMap.find(index) ==
            this->_characterMap.end())
        {
            return Glyph::empty();
        }
        return this->_characterMap[index];
    }
    
private:
    std::map<GLchar, Glyph> _characterMap;
};

