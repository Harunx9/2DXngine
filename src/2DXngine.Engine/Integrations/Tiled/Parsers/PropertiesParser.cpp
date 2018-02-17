#include "PropertiesParser.h"

std::vector<Property> PropertiesParser::parse(const pugi::xml_node& node)
{
    auto vec = std::vector<Property>();

    for (auto& child : node.children())
    {
        auto name = child.attribute("name").as_string();
        auto type = child.attribute("type").as_string();
        auto value = child.attribute("value").as_string();
        vec.push_back(Property(name, type, value));
    }

    return vec;
}
