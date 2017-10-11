#pragma once
#include "../../../ContentManagement/AssetPath.h"
class SpriteSheetComponent;

class XMLSpritesheetParserFactory
{
public:
    static SpriteSheetComponent* create(AssetPath path);
private:
    XMLSpritesheetParserFactory() = delete;
    XMLSpritesheetParserFactory(XMLSpritesheetParserFactory& other) = delete;
    ~XMLSpritesheetParserFactory() = delete;
};
