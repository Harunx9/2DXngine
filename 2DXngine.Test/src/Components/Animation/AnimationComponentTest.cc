#include "gtest\gtest.h"
#include <Components\Graphics\AnimationFactory\XMLSpritesheetAnimationFactory.h>
#include <Components\Graphics\AnimationComponent.h>

TEST(AnimationComponentTest, when_animation_coponent_is_started_proper_animation_will_start)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim = animations["animationName1"];
    AnimationComponent* cmp = new AnimationComponent(animations);

    cmp->play_animation("animationName1");

    ASSERT_TRUE(anim->get_isPlaying());
    ASSERT_FALSE(anim->get_isLooped());
}

TEST(AnimationComponentTest, when_animation_component_is_started_proper_animation_will_start_with_loop)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim = animations["animationName1"];
    AnimationComponent* cmp = new AnimationComponent(animations);

    cmp->play_animation("animationName1", true);

    ASSERT_TRUE(anim->get_isPlaying());
    ASSERT_TRUE(anim->get_isLooped());
}

TEST(AnimationComponentTest, when_animation_comonent_can_pause_started_animation)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim = animations["animationName1"];
    AnimationComponent* cmp = new AnimationComponent(animations);
    cmp->play_animation("animationName1");
    
    cmp->pause_animation();

    ASSERT_FALSE(anim->get_isPlaying());
}

TEST(AnimationComponentTest, when_animation_comonent_play_other_animation_current_will_be_paused)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim1 = animations["animationName1"];
    Animation* anim2 = animations["animationName2"];
    AnimationComponent* cmp = new AnimationComponent(animations);
    cmp->play_animation("animationName1");

    cmp->play_animation("animationName2");

    ASSERT_FALSE(anim1->get_isPlaying());
    ASSERT_TRUE(anim2->get_isPlaying());
}
