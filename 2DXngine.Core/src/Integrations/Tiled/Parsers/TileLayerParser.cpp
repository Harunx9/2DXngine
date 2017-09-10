#include "TileLayerParser.h"
#include "../../../Utils/StringUtils.h"

namespace TileLayerConst {
    const char* name = "name";
    const char* x = "x";
    const char* y = "y";
    const char* width = "width";
    const char* height = "height";
    const char* opacity = "opacity";
    const char* visible = "visible";
    const char* offsetx = "offsetx";
    const char* offsety = "offsety";
    const char* order = "order";
}

TileLayerParser::TileLayerParser()
{
}


TileLayerParser::~TileLayerParser()
{
}

TileLayer TileLayerParser::parse(pugi::xml_node & node)
{
    TileLayer layer = this->parseAttributes(node);

    auto properties = node.child("properties");
    if (properties.empty() == false)
    {
        auto parsedProps = this->_propParser.parse(node);
        layer.addProperties(parsedProps);
    }

    auto data = node.child("data");
    if (data.empty() == false)
    {
        Data parsedData = this->parseData(data);
        layer.set_data(parsedData);
    }

    return layer;
}

TileLayer TileLayerParser::parseAttributes(pugi::xml_node & node)
{
    auto  name = node.attribute(TileLayerConst::name);
    auto  x = node.attribute(TileLayerConst::x);
    auto  y = node.attribute(TileLayerConst::y);
    auto  width = node.attribute(TileLayerConst::width);
    auto  height = node.attribute(TileLayerConst::height);
    auto  opacity = node.attribute(TileLayerConst::opacity);
    auto  visible = node.attribute(TileLayerConst::visible);
    auto  offsetx = node.attribute(TileLayerConst::offsetx);
    auto  offsety = node.attribute(TileLayerConst::offsety);

    return {
        std::string(name.as_string()),
        x.empty() ? 0 : x.as_int(),
        y.empty() ? 0 : y.as_int(),
        width.as_int(),
        height.as_int(),
        opacity.empty() ? 1.f : opacity.as_float(),
        visible.empty() ? true : visible.as_bool(),
        offsetx.empty() ? 0 : offsetx.as_int(),
        offsety.empty() ? 0 : offsety.as_int()
    };
}

Data TileLayerParser::parseData(pugi::xml_node & node)
{
    Data data;
    auto encoding = node.attribute("encoding");
    if (encoding.empty() == false)
    {
        std::string encodingName = encoding.as_string();
        if (encodingName.compare("csv") == 0)
        {
            data = this->parseCSV(node);
        }
        else if (encodingName.compare("base64") == 0)
        {
            data = this->parseBase64(node);
        }
    }
    return data;
}

Data TileLayerParser::parseBase64(pugi::xml_node & node)
{
    std::string dataVal = node.child_value();
    dataVal = stringutils::trim(dataVal);
    const int nextTile = 4;

    auto decoded = stringutils::Base64decode(dataVal);

    std::vector<Tile> tiles;
    for (size_t i = 0; i < decoded.length(); i += nextTile)
    {
        int tileid = decoded[i];
        tiles.push_back({ tileid });
    }

    return {
        tiles
    };
}

Data TileLayerParser::parseCSV(pugi::xml_node & node)
{
    std::string dataVal = node.child_value();
    auto splitted = stringutils::split(dataVal, ',');

    std::vector<Tile> tiles;

    for (auto& tileid : splitted)
    {
        tiles.push_back({ std::stoi(tileid) });
    }

    return {
        tiles
    };
}
