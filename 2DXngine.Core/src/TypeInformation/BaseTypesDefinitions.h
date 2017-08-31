#pragma once

#include "TypeInfo.h"
#include "../Components/Components.h"

DECLARE_TYPE_INFO(Component, "")
DECLARE_TYPE_INFO(DrawableComponent, Component)
DECLARE_TYPE_INFO(UpdateableComponent, Component)
DECLARE_TYPE_INFO(SpriteComponent, Component)
DECLARE_TYPE_INFO(Transform, Component)
DECLARE_TYPE_INFO(SpriteDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(ColliderComponent, Component)
DECLARE_TYPE_INFO(AnimationComponent, UpdateableComponent)
DECLARE_TYPE_INFO(AnimationDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(ClickableComponent, UpdateableComponent)
DECLARE_TYPE_INFO(TextComponent, Component)
DECLARE_TYPE_INFO(FontComponent, Component)
DECLARE_TYPE_INFO(FontDrawableComponent, DrawableComponent)

#ifdef main
DEFINE_TYPE_INFO(Component);
DEFINE_TYPE_INFO(DrawableComponent);
DEFINE_TYPE_INFO(UpdateableComponent);
DEFINE_TYPE_INFO(SpriteComponent);
DEFINE_TYPE_INFO(Transform);
DEFINE_TYPE_INFO(SpriteDrawableComponent);
DEFINE_TYPE_INFO(ColliderComponent);
DEFINE_TYPE_INFO(AnimationComponent);
DEFINE_TYPE_INFO(AnimationDrawableComponent);
DEFINE_TYPE_INFO(ClickableComponent);
DEFINE_TYPE_INFO(TextComponent);
DEFINE_TYPE_INFO(FontComponent);
DEFINE_TYPE_INFO(FontDrawableComponent);
#endif