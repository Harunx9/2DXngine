#include "TTFont.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>
#include "../../Graphics/SpriteBatch.h"
#include "../ContentManagerService.h"
#include "../../Services/ServiceLocator.h"
#include "ShaderProgram.h"
#include "../../Graphics/Shaders/StandardFontShader.h"


TTFont::TTFont(AssetPath path) : Asset(path, DefaultAssetType::TTF_TYPE)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
        std::exit(1);

    auto strPath = path.get_fullPath();
    auto charPath = strPath.c_str();

    FT_Face face;
    if (FT_New_Face(ft, charPath, 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, 48);

    for (GLubyte letter = 0; letter < 128; letter++)
    {
        if (FT_Load_Char(face, letter, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }

        Bitmap* bmp = new Bitmap(face->glyph->bitmap.buffer, face->glyph->bitmap.width, face->glyph->bitmap.rows);
        Texture* texture = new Texture(AssetPath::empty(), bmp, GL_RED);

        Glyph character = {
            texture,
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            glm::ivec2(face->glyph->advance.x,face->glyph->advance.y),
            GlyphState::FILL_GLYPH
        };
        this->_characterMap.insert(std::pair<GLchar, Glyph>(letter, character));
    }
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    this->_fontShader = new ShaderProgram(StdFontShader::vertexSource, StdFontShader::fragmentSource);
    auto compileResult = this->_fontShader->compile();

    if(compileResult == ProgramCompilationResult::COMPILE_ERROR)
        std::exit(1);
}

TTFont::~TTFont()
{
    for (auto& pair : this->_characterMap)
    {
        delete pair.second.tex;
    }
    this->_characterMap.clear();
}

TTFont * TTFont::load(AssetPath path)
{
    return new TTFont(path);
}

void TTFont::draw(SpriteBatch * batch, std::string text, glm::vec2 position, Color color, glm::mat4 camera)
{
    this->draw(batch, text, position, 1.f, color, camera);
}

void TTFont::draw(SpriteBatch * batch, std::string text, glm::vec2 position, float scale, Color color, glm::mat4 camera)
{
    this->draw(batch, text, position, glm::vec2(scale, scale), color, camera);
}

void TTFont::draw(SpriteBatch * batch, std::string text, glm::vec2 position, glm::vec2 scale, Color color, glm::mat4 camera)
{
    bool wasStarted = false;
    ShaderProgram* latestShader = nullptr;

    if (batch->get_isStarted())
    {
        latestShader = batch->get_customShader();
        batch->end();
        wasStarted = true;
    }

    batch->begin(this->_fontShader, TextureWrap::CLAMP_TO_EDGE, TextureFilter::LINEAR_FILTER, camera);
    for (auto c : text)
    {
        Glyph g = this->_characterMap[c];
        if (g.state != GlyphState::EMPTY_GLYPH)
        {
            //compute base pos variables
            float x = position.x + g.bearing.x * scale.x;
            float y = position.y - g.bearing.y * scale.y;

            float width = g.tex->get_bitmap()->get_width() * scale.x;
            float height = g.tex->get_bitmap()->get_height() * scale.y;

            batch->draw(g.tex, RectangleI(x, y, width, height), color, 0);

            position.x += (g.advance.x >> 6) * scale.x;
            position.y += (g.advance.y >> 6) * scale.y;
        }
    }

    batch->end();
    if (wasStarted)
    {
        batch->begin(latestShader, TextureWrap::REPEAT, TextureFilter::POINT_FILTER, camera);
    }
}
