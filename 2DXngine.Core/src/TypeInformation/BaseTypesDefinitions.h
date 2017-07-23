#pragma once

#include "TypeInfo.h"
#include "../ComponentModel/Component.h"
#include "../ComponentModel/DrawableComponent.h"
#include "../ComponentModel/UpdateableComponent.h"
#include "../Components/Graphics/SpriteComponent.h"
#include "../Components/Graphics/SpriteDrawableComponent.h"
#include "../Components/Graphics/Transform.h"

#ifdef main
DECLARE_TYPE_INFO(Component, "")
DECLARE_TYPE_INFO(DrawableComponent, Component)
DECLARE_TYPE_INFO(UpdateableComponent, Component)
DECLARE_TYPE_INFO(SpriteComponent, Component)
DECLARE_TYPE_INFO(Transform, Component)
DECLARE_TYPE_INFO(SpriteDrawableComponent, DrawableComponent)

DEFINE_TYPE_INFO(Component);
DEFINE_TYPE_INFO(DrawableComponent);
DEFINE_TYPE_INFO(UpdateableComponent);
DEFINE_TYPE_INFO(SpriteComponent);
DEFINE_TYPE_INFO(Transform);
DEFINE_TYPE_INFO(SpriteDrawableComponent);
#else
DECLARE_TYPE_INFO(Component, "")
DECLARE_TYPE_INFO(DrawableComponent, Component)
DECLARE_TYPE_INFO(UpdateableComponent, Component)
DECLARE_TYPE_INFO(SpriteComponent, Component)
DECLARE_TYPE_INFO(SpriteDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(Transform, Component)
#endif