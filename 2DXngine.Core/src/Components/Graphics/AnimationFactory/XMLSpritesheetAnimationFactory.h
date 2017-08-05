#pragma once
#include <string>
#include <vector>
#include "../../../ContentManagement/AssetPath.h"
#include "../AnimationComponent.h"

struct AnimationDefinition
{
    std::string name;
    int firstFrame;
    size_t lenght;
    int framesPerSecond;
};

class XMLSpritesheetAnimationFactory
{
public:
    XMLSpritesheetAnimationFactory() = delete;
    XMLSpritesheetAnimationFactory(XMLSpritesheetAnimationFactory& other) = delete;
    ~XMLSpritesheetAnimationFactory() = delete;

    static AnimationComponent* createFromXml(AssetPath path, std::vector<AnimationDefinition> animationsDefinitions);
    static AnimationComponent* createFromXmlWithDefinedNames(AssetPath path, std::vector<std::string> animationsNames);
    static AnimationComponent* createFromXmlWithAllNames(AssetPath path);
};

class XMLAnimationSpritesheetParser
{
public:
    XMLAnimationSpritesheetParser() = delete;
    XMLAnimationSpritesheetParser(XMLAnimationSpritesheetParser& other) = delete;
    ~XMLAnimationSpritesheetParser() = delete;

    static animations_dict loadWithSpecifiedNames(AssetPath path, std::vector<std::string> animationsNames);
    static animations_dict load(AssetPath path);
};

class XMLSpritesheetParser
{
public:
    XMLSpritesheetParser() = delete;
    XMLSpritesheetParser(XMLSpritesheetParser& other) = delete;
    ~XMLSpritesheetParser() = delete;

    static std::vector<RectangleI> load(AssetPath path);
};
