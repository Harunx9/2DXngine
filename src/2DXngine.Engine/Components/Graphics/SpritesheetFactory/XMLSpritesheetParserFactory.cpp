#include "XMLSpritesheetParserFactory.h"
#include "../SpriteSheetComponent.h"
#include "../../../../../thirdparty/pugixml/src/pugixml.hpp"
#include <string>

// Animation xml scheme with names
//<spritesheet>
//    <item name="anim_1" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_2" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_3" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_4" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_5" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_6" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_7" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    <item name="anim_8" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//</spritesheet>
SpriteSheetComponent* XMLSpritesheetParserFactory::create(AssetPath path)
{
    auto fullPath = path.get_fullPath();
    auto c_strFullPath = fullPath.c_str();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(c_strFullPath);
    std::map<std::string, RectangleI> parsedSheet;
    if (result)
    {
        auto  root = doc.child("spritesheet");
        for (auto& item : root.children("item"))
        {
            auto name = item.attribute("name").as_string();
            int x = item.attribute("x").as_int();
            int y = item.attribute("y").as_int();
            int width = item.attribute("width").as_int();
            int height = item.attribute("height").as_int();
            int offsetx = item.attribute("offsetx").as_int();
            int offsety = item.attribute("offsety").as_int();

            parsedSheet[std::string(name)] = RectangleI(x + offsetx, y + offsety, width, height);
        }
    }

    return new SpriteSheetComponent(parsedSheet);
}