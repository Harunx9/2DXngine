#pragma once

#include "TypeInfo.h"
#include "../ComponentModel/Component.h"
#include "../ComponentModel/DrawableComponent.h"
#include "../ComponentModel/UpdateableComponent.h"
#include "../Components/Graphics/SpriteComponent.h"
#include "../Components/Graphics/SpriteDrawableComponent.h"
#include "../Components/Graphics/Transform.h"
#include "../Components/Graphics/AnimationComponent.h"
#include "../Components/Graphics/AnimationDrawableComponent.h"
#include "../Components/Interactions/ColliderComponent.h"

#ifdef main
DECLARE_TYPE_INFO(Component, "")
DECLARE_TYPE_INFO(DrawableComponent, Component)
DECLARE_TYPE_INFO(UpdateableComponent, Component)
DECLARE_TYPE_INFO(SpriteComponent, Component)
DECLARE_TYPE_INFO(Transform, Component)
DECLARE_TYPE_INFO(SpriteDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(ColliderComponent, Component)
DECLARE_TYPE_INFO(AnimationComponent, UpdateableComponent)
DECLARE_TYPE_INFO(AnimationDrawableComponent, DrawableComponent)


DEFINE_TYPE_INFO(Component);
DEFINE_TYPE_INFO(DrawableComponent);
DEFINE_TYPE_INFO(UpdateableComponent);
DEFINE_TYPE_INFO(SpriteComponent);
DEFINE_TYPE_INFO(Transform);
DEFINE_TYPE_INFO(SpriteDrawableComponent);
DEFINE_TYPE_INFO(ColliderComponent);
DEFINE_TYPE_INFO(AnimationComponent);
DEFINE_TYPE_INFO(AnimationDrawableComponent);
#else
DECLARE_TYPE_INFO(Component, "")
DECLARE_TYPE_INFO(DrawableComponent, Component)
DECLARE_TYPE_INFO(UpdateableComponent, Component)
DECLARE_TYPE_INFO(SpriteComponent, Component)
DECLARE_TYPE_INFO(SpriteDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(Transform, Component)
DECLARE_TYPE_INFO(ColliderComponent, Component)
DECLARE_TYPE_INFO(AnimationComponent, UpdateableComponent)
DECLARE_TYPE_INFO(AnimationDrawableComponent, DrawableComponent)
#endif