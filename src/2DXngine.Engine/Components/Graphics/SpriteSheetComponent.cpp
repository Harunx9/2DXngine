#include "SpriteSheetComponent.h"

SpriteSheetComponent::SpriteSheetComponent(std::map<std::string, RectangleI> sheet) :
    Component("SpriteSheetComponent"),
    _sheet(sheet)
{
}

SpriteSheetComponent::~SpriteSheetComponent()
{
}