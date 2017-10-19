#pragma once
#include <map>
#include <vector>
#include <string>
#include <functional>
#include "../../ComponentModel/Component.h"
#include "../../Utils/Math/RectangleI.h"

class SpriteSheetComponent : public Component
{
public:
    ADD_TYPE_META_INFO()
    SpriteSheetComponent(std::map<std::string, RectangleI> sheet);
    ~SpriteSheetComponent();

    virtual void initialize(bool force = false) override {}
    virtual void terminate() override {}

    RectangleI get_spriteRect(const char* name)
    {
        return this->_sheet[name];
    }

    RectangleI* get_allFrames()
    {
        RectangleI* rects = new RectangleI[this->_sheet.size()];
        size_t index = 0;
        
        for (auto& pair : this->_sheet)
        {
            rects[index] = pair.second;
            ++index;
        }

        return rects;
    }

    std::vector<RectangleI> filterFrames(std::function<bool(std::pair<std::string, RectangleI>)> predicate)
    {
        std::vector<RectangleI> rects;

        for (auto& pair : this->_sheet)
        {
            if (predicate(pair))
                rects.push_back(pair.second);
        }

        return rects;
    }

    int get_sheetSize() const
    {
        return this->_sheet.size();
    }
private:
    std::map<std::string, RectangleI> _sheet;
};

