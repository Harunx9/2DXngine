#include "XMLSpritesheetAnimationFactory.h"
#include <vector>
#include "../pugixml/src/pugixml.hpp"

AnimationComponent * XMLSpritesheetAnimationFactory::createFromXml(AssetPath path, std::vector<AnimationDefinition> animationsDefinitions)
{
    std::vector<RectangleI> frames = XMLSpritesheetParser::load(path);
    if (frames.empty())
        return nullptr;

    animations_dict animations;

    for (auto& definition : animationsDefinitions)
    {

        RectangleI* tmpFrames = new RectangleI[definition.lenght];

        for (size_t currentFrame = 0;
            currentFrame < definition.lenght;
            currentFrame++)
        {
            tmpFrames[currentFrame] = frames[currentFrame + definition.firstFrame];
        }

        Animation* animation = new Animation(definition.name, definition.framesPerSecond,
            definition.lenght, tmpFrames);

        animations[definition.name] = animation;
    }

    return new AnimationComponent(animations);
}

AnimationComponent * XMLSpritesheetAnimationFactory::createFromXmlWithDefinedNames(AssetPath path, std::vector<std::string> animationsNames)
{
    animations_dict animations = XMLAnimationSpritesheetParser::loadWithSpecifiedNames(path, animationsNames);
    if (animations.empty())
        return nullptr;

    return new AnimationComponent(animations);
}

AnimationComponent * XMLSpritesheetAnimationFactory::createFromXmlWithAllNames(AssetPath path)
{
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    if (animations.empty())
        return nullptr;

    return new AnimationComponent(animations);
}


// Animation xml scheme with names
//<animations>
//    <animation name="animationName1">
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    </animation>
//    <animation name="animationName2">
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    </animation>
//</animations>
//This method parse animation with specified names
animations_dict XMLAnimationSpritesheetParser::loadWithSpecifiedNames(AssetPath path, std::vector<std::string> animationsNames)
{
    auto fullPath = path.get_fullPath();
    auto c_strFullPath = fullPath.c_str();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(c_strFullPath);
    animations_dict animations;

    if (result)
    {
        auto  root = doc.child("animations");
        for (auto& animationName : animationsNames)
        {
            for (auto& animation : root.children("animation"))
            {
                if (animationName == std::string(animation.attribute("name").as_string()))
                {
                    Animation * animTmp = nullptr;
                    std::vector<RectangleI> frames;
                    for (auto& frame : animation.children("frame"))
                    {
                        int x = frame.attribute("x").as_int();
                        int y = frame.attribute("y").as_int();
                        int width = frame.attribute("width").as_int();
                        int height = frame.attribute("height").as_int();
                        int offsetx = frame.attribute("offsetx").as_int();
                        int offsety = frame.attribute("offsety").as_int();

                        frames.push_back(RectangleI(x + offsetx, y + offsety, x + width + offsetx, y + height + offsety));
                    }

                    animTmp = new Animation(
                        animation.attribute("name").as_string(),
                        animation.attribute("framesPerSecond").as_int(),
                        frames.size(), frames.data());

                    animations[animation.attribute("name").as_string()] = animTmp;
                }
            }
        }
    }

    return animations;
}


// Animation xml scheme with names
//<animations>
//    <animation name="animationName1" framesPerSecond="4">
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="1" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="2" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="3" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    </animation>
//    <animation name="animationName2" framesPerSecond="4">
//        <frame number="0" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="1" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="2" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//        <frame number="3" x="0" y="0" width="50" height="50" offsetx="0" offsety="0"/>
//    </animation>
//</animations>
//This method parse animation with names
animations_dict XMLAnimationSpritesheetParser::load(AssetPath path)
{
    auto fullPath = path.get_fullPath();
    auto c_strFullPath = fullPath.c_str();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(c_strFullPath);
    animations_dict animations;

    if (result)
    {
        auto  root = doc.child("animations");
        for (auto& animation : root.children("animation"))
        {
            Animation * animTmp;
            std::vector<RectangleI> frames = std::vector<RectangleI>();
            for (auto& frame : animation.children("frame"))
            {
                int x = frame.attribute("x").as_int();
                int y = frame.attribute("y").as_int();
                int width = frame.attribute("width").as_int();
                int height = frame.attribute("height").as_int();
                int offsetx = frame.attribute("offsetx").as_int();
                int offsety = frame.attribute("offsety").as_int();

                frames.push_back(RectangleI(x + offsetx, y + offsety, width, height));
            }
            RectangleI* rectPtr = new RectangleI[frames.size()];
            std::copy(frames.begin(), frames.end(), rectPtr);
            animTmp = new Animation(
                animation.attribute("name").as_string(),
                animation.attribute("framesPerSecond").as_int(),
                frames.size(), rectPtr);

            animations[animation.attribute("name").as_string()] = animTmp;
        }
    }

    return animations;
}

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
std::vector<RectangleI> XMLSpritesheetParser::load(AssetPath path)
{
    auto fullPath = path.get_fullPath();
    auto c_strFullPath = fullPath.c_str();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(c_strFullPath);
    std::vector<RectangleI> frames;

    if (result)
    {
        auto  root = doc.child("spritesheet");
        for (auto& item : root.children("item"))
        {
            int x = item.attribute("x").as_int();
            int y = item.attribute("y").as_int();
            int width = item.attribute("width").as_int();
            int height = item.attribute("height").as_int();
            int offsetx = item.attribute("offsetx").as_int();
            int offsety = item.attribute("offsety").as_int();

            frames.push_back(RectangleI(x + offsetx, y + offsety, x + width + offsetx, y + height + offsety));
        }
    }

    return frames;
}
