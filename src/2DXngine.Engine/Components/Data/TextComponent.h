#pragma once
#include "../../ComponentModel/Component.h"

class TextComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
    TextComponent(std::string text);
    ~TextComponent();

    virtual void initialize(bool force = false) override;
    virtual void terminate() override;

    READONLY_PROPERTY(std::string, text)
};

