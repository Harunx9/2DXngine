#include "TTFont.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>


TTFont::TTFont(AssetPath path): Asset(path, DefaultAssetType::TTF_TYPE)
{
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
        std::exit(1);

    FT_Face face;
    if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, 48);

    for (GLubyte letter = 0; letter < 128; letter++)
    {
        if (FT_Load_Char(face, letter, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }

        GLuint texture;
        glGenTextures(1, &texture);
        Glyph character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
        this->_characterMap.insert(std::pair<GLchar, Glyph>(letter, character));
    }
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}


TTFont::~TTFont()
{
    this->_characterMap.clear();
}

TTFont * TTFont::load(AssetPath path)
{
    return nullptr;
}
