#pragma once

#include "TypeInfo.h"
#include "../Components/Components.h"
#include "../Integrations/Tiled/Components/Components.h"

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
DECLARE_TYPE_INFO(TiledMapLayerOrtoDrawable, DrawableComponent)
DECLARE_TYPE_INFO(TileSetComponent, Component)
DECLARE_TYPE_INFO(TiledLayerComponent, Component)
DECLARE_TYPE_INFO(ParticleSystemBehavior, UpdateableComponent)
DECLARE_TYPE_INFO(ParticleSystemDrawableComponent, DrawableComponent)
DECLARE_TYPE_INFO(SpriteSheetComponent, Component)
DECLARE_TYPE_INFO(NavMeshComponent, Component)
DECLARE_TYPE_INFO(NavMeshLayerComponent, Component)

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
DEFINE_TYPE_INFO(TiledMapLayerOrtoDrawable);
DEFINE_TYPE_INFO(TileSetComponent);
DEFINE_TYPE_INFO(TiledLayerComponent);
DEFINE_TYPE_INFO(ParticleSystemBehavior);
DEFINE_TYPE_INFO(ParticleSystemDrawableComponent);
DEFINE_TYPE_INFO(SpriteSheetComponent);
DEFINE_TYPE_INFO(NavMeshComponent);
DEFINE_TYPE_INFO(NavMeshLayerComponent);
#endif