#pragma once
#include <vector>
#include "../DataStructures/Property.h"
#include "../pugixml/src/pugixml.hpp"

class PropertiesParser
{
public:
    std::vector<Property> parse(pugi::xml_node& node);
};

