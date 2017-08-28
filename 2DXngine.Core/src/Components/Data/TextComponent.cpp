#include "TextComponent.h"

TextComponent::TextComponent(std::string text): Component("TextComponent"),
    _text(text)
{
}

TextComponent::~TextComponent()
{
}

void TextComponent::initialize(bool force)
{
}

void TextComponent::terminate()
{
}
