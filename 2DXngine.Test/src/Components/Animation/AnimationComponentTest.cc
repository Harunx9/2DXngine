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

TEST(AnimationComponentTest, when_animation_started_it_should_return_first_frame)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim1 = animations["animationName1"];
    AnimationComponent* cmp = new AnimationComponent(animations);
    
    cmp->play_animation("animationName1");

    ASSERT_EQ(cmp->get_currentFrame().get_x(), 0);
    ASSERT_EQ(cmp->get_currentFrame().get_y(), 0);
    ASSERT_EQ(cmp->get_currentFrame().get_width(), 50);
    ASSERT_EQ(cmp->get_currentFrame().get_height(), 50);
}

TEST(AnimationComponentTest, when_animation_started_and_updated_it_should_return_second_frame)
{
    AssetPath path = AssetPath::create("Content\\testanimationsheet.xml");
    animations_dict animations = XMLAnimationSpritesheetParser::load(path);
    Animation* anim1 = animations["animationName1"];
    AnimationComponent* cmp = new AnimationComponent(animations);

    cmp->play_animation("animationName1");
    cmp->update(32.f);

    ASSERT_EQ(cmp->get_currentFrame().get_x(), 50);
    ASSERT_EQ(cmp->get_currentFrame().get_y(), 0);
    ASSERT_EQ(cmp->get_currentFrame().get_width(), 50);
    ASSERT_EQ(cmp->get_currentFrame().get_height(), 50);
}

