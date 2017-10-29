set(ENGINE_SOURCE_FILES

        AppImplementations/App.h
        AppImplementations/App.cpp
        AppImplementations/WindowApp.h
        AppImplementations/WindowApp.cpp
        
        AppImplementations/Builder/AppBuilder.h
        AppImplementations/Builder/AppBuilder.cpp

        AppImplementations/SDLEvents/SDLEventsMapperService.h
        AppImplementations/SDLEvents/SDLEventsMapperService.cpp
        AppImplementations/SDLEvents/SDLEventMapper.h
        AppImplementations/SDLEvents/SDLEventMapper.cpp
    
        AppImplementations/SDLEvents/Mappers/WindowEventsMapper.h
        AppImplementations/SDLEvents/Mappers/WindowEventsMapper.cpp
        AppImplementations/SDLEvents/Mappers/MouseEventsMapper.h
        AppImplementations/SDLEvents/Mappers/MouseEventsMapper.cpp
        AppImplementations/SDLEvents/Mappers/KeyboardEventMapper.h
        AppImplementations/SDLEvents/Mappers/KeyboardEventMapper.cpp
        
        Audio/MusicService.h
        Audio/MusicService.cpp
        Audio/SoundService.h
        Audio/SoundService.cpp

        ComponentModel/Component.h
        ComponentModel/Component.cpp
        ComponentModel/DrawableComponent.h
        ComponentModel/DrawableComponent.cpp
        ComponentModel/GameObject.h
        ComponentModel/GameObject.cpp
        ComponentModel/UpdateableComponent.h
        ComponentModel/UpdateableComponent.cpp
        ComponentModel/GameObjectManager.h
        ComponentModel/GameObjectManager.cpp
        ComponentModel/GameObjectFilterFunctions.h
        Components/Components.h

        Components/Behaviors/ParticleSystem/BaseTypes.h
        Components/Behaviors/ParticleSystem/BaseTypes.cpp
        Components/Behaviors/ParticleSystem/ParticleUpdaters.h
        Components/Behaviors/ParticleSystem/ParticleUpdaters.cpp
        Components/Behaviors/ParticleSystem/ParticleGenerators.h
        Components/Behaviors/ParticleSystem/ParticleGenerators.cpp
        Components/Behaviors/ParticleSystem/ParticleSystemBehavior.h
        Components/Behaviors/ParticleSystem/ParticleSystemBehavior.cpp

        Components/Data/FontComponent.h
        Components/Data/FontComponent.cpp
        Components/Data/TextComponent.h
        Components/Data/TextComponent.cpp

        Components/Graphics/AnimationFactory/Animation.h
        Components/Graphics/AnimationFactory/Animation.cpp
        Components/Graphics/AnimationFactory/XMLSpritesheetAnimationFactory.h
        Components/Graphics/AnimationFactory/XMLSpritesheetAnimationFactory.cpp
        Components/Graphics/SpritesheetFactory/XMLSpritesheetParserFactory.h
        Components/Graphics/SpritesheetFactory/XMLSpritesheetParserFactory.cpp
        Components/Graphics/AnimationComponent.h
        Components/Graphics/AnimationComponent.cpp
        Components/Graphics/AnimationDrawableComponent.h
        Components/Graphics/AnimationDrawableComponent.cpp
        Components/Graphics/SpriteComponent.h
        Components/Graphics/SpriteComponent.cpp
        Components/Graphics/FontDrawableComponent.h
        Components/Graphics/FontDrawableComponent.cpp
        Components/Graphics/SpriteDrawableComponent.h
        Components/Graphics/SpriteDrawableComponent.cpp
        Components/Graphics/Transform.h
        Components/Graphics/Transform.cpp
        Components/Graphics/SpriteSheetComponent.h
        Components/Graphics/SpriteSheetComponent.cpp
        Components/Graphics/ParticleSystemDrawable.h
        Components/Graphics/ParticleSystemDrawable.cpp

        Components/Interactions/ClickableComponent.h
        Components/Interactions/ClickableComponent.cpp
        Components/Interactions/ColliderComponent.h
        Components/Interactions/ColliderComponent.cpp

        Config/ConfigSection.h
        Config/ConfigSection.cpp
        Config/AudioConfig.h
        Config/AudioConfig.cpp
        Config/ActionsConfig.h
        Config/ActionsConfig.cpp
        Config/ConfigurationService.h
        Config/ConfigurationService.cpp
        Config/GraphicConfig.h
        Config/GraphicConfig.cpp
        Config/LanguageConfig.h
        Config/LanguageConfig.cpp
        Config/LoggerConfig.h
        Config/LoggerConfig.cpp

        ContentManagement/DefaultAssets/Bitmap.h
        ContentManagement/DefaultAssets/Bitmap.cpp
        ContentManagement/DefaultAssets/Mp3Sound.h
        ContentManagement/DefaultAssets/Mp3Sound.cpp
        ContentManagement/DefaultAssets/OggSound.h
        ContentManagement/DefaultAssets/OggSound.cpp
        ContentManagement/DefaultAssets/Shader.h
        ContentManagement/DefaultAssets/Shader.cpp
        ContentManagement/DefaultAssets/ShaderProgram.h
        ContentManagement/DefaultAssets/ShaderProgram.cpp
        ContentManagement/DefaultAssets/Sound.h
        ContentManagement/DefaultAssets/Texture.h
        ContentManagement/DefaultAssets/Texture.cpp
        ContentManagement/DefaultAssets/TTFont.h
        ContentManagement/DefaultAssets/TTFont.cpp
        ContentManagement/DefaultAssets/WavSound.h
        ContentManagement/DefaultAssets/WavSound.cpp

        ContentManagement/Asset.h
        ContentManagement/Asset.cpp
        ContentManagement/AssetPath.h
        ContentManagement/AssetPath.cpp
        ContentManagement/AssetTypes.h
        ContentManagement/AssetTypes.cpp
        ContentManagement/ContentManagerService.h
        ContentManagement/ContentManagerService.cpp

        Graphics/Shaders/StandardFontShader.h
        Graphics/Shaders/StandardTextureShader.h
        
        Graphics/Camera.h
        Graphics/Camera.cpp
        Graphics/Color.h
        Graphics/GraphicDevice.h
        Graphics/Renderer.h
        Graphics/Renderer.cpp
        Graphics/RenderTarget.h
        Graphics/RenderTarget.cpp
        Graphics/SamplerState.h
        Graphics/SamplerState.cpp
        Graphics/SpriteBatch.h
        Graphics/SpriteBatch.cpp

        Input/InputDefines.h
        Input/InputService.h
        Input/InputService.cpp
        Input/KeyboardStateHandler.h
        Input/KeyboardStateHandler.cpp
        Input/MouseStateHandler.h
        Input/MouseStateHandler.cpp

        Integrations/Tiled/Components/Components.h
        Integrations/Tiled/Components/TiledLayerComponent.h
        Integrations/Tiled/Components/TiledLayerComponent.cpp
        Integrations/Tiled/Components/TiledMapLayerOrtoDrawable.h
        Integrations/Tiled/Components/TiledMapLayerOrtoDrawable.cpp
        Integrations/Tiled/Components/TileSetComponent.h
        Integrations/Tiled/Components/TileSetComponent.cpp

        Integrations/Tiled/DataStructures/Group.h
        Integrations/Tiled/DataStructures/ImageLayer.h
        Integrations/Tiled/DataStructures/ObjectLayer.h
        Integrations/Tiled/DataStructures/Property.h
        Integrations/Tiled/DataStructures/TiledMap.h
        Integrations/Tiled/DataStructures/TileLayer.h
        Integrations/Tiled/DataStructures/TileSet.h

        Integrations/Tiled/Factories/TileLayersFactory.h
        Integrations/Tiled/Factories/TileLayersFactory.cpp
        Integrations/Tiled/Factories/TilesetsFactory.h
        Integrations/Tiled/Factories/TilesetsFactory.cpp

        Integrations/Tiled/Parsers/TiledXMLDefines.h
        Integrations/Tiled/Parsers/GroupParser.h
        Integrations/Tiled/Parsers/GroupParser.cpp
        Integrations/Tiled/Parsers/ImageLayerParser.h
        Integrations/Tiled/Parsers/ImageLayerParser.cpp
        Integrations/Tiled/Parsers/ObjectGroupParser.h
        Integrations/Tiled/Parsers/ObjectGroupParser.cpp
        Integrations/Tiled/Parsers/PropertiesParser.h
        Integrations/Tiled/Parsers/PropertiesParser.cpp
        Integrations/Tiled/Parsers/TileLayerParser.h
        Integrations/Tiled/Parsers/TileLayerParser.cpp
        Integrations/Tiled/Parsers/TileMapParser.h
        Integrations/Tiled/Parsers/TileMapParser.cpp
        Integrations/Tiled/Parsers/TilesetParser.h
        Integrations/Tiled/Parsers/TilesetParser.cpp

        Integrations/Tiled/GameObjectFactory.h
        Integrations/Tiled/GameObjectFactories.h
        Integrations/Tiled/GameObjectFactories.cpp
        Integrations/Tiled/TiledMapLoader.h
        Integrations/Tiled/TiledMapLoader.cpp

        Scenes/PostProcessing/PostProcessTask.h
        Scenes/PostProcessing/PostProcessTask.cpp

        Scenes/LoadableScene.h
        Scenes/LoadableScene.cpp
        Scenes/PostProcessHandler.h
        Scenes/PostProcessHandler.cpp
        Scenes/Scene.h
        Scenes/Scene.cpp
        Scenes/SceneBehavior.h
        Scenes/SceneBehavior.cpp
        Scenes/SceneBehaviorManager.h
        Scenes/SceneBehaviorManager.cpp
        Scenes/SceneLayer.h
        Scenes/SceneLayer.cpp
        Scenes/SceneLoader.h
        Scenes/SceneManagerService.h
        Scenes/SceneManagerService.cpp
        Scenes/SceneRenderSystem.h
        Scenes/SceneRenderSystem.cpp
        Scenes/SceneUpdateSystem.h
        Scenes/SceneUpdateSystem.cpp

        Services/Service.h
        Services/Service.cpp
        Services/ServiceLocator.h
        Services/ServiceLocator.cpp

        Translations/TFunction.h
        Translations/TranslationService.h
        Translations/TranslationService.cpp
        
        TypeInformation/BaseTypesDefinitions.h
        TypeInformation/BaseTypesDeclarations.cpp
        TypeInformation/TypeCache.h
        TypeInformation/TypeCache.cpp
        TypeInformation/TypeIdHelper.h
        TypeInformation/TypeInfo.h
        TypeInformation/TypeInfo.cpp
        TypeInformation/TypeMetaInfo.h
        
        Utils/Errors/Result.h
        Utils/Errors/Result.cpp

        Utils/Events/EventArgs.h
        Utils/Events/EventHandler.h
        Utils/Events/EventHandler.cpp

        Utils/Logger/LoggersImpl/Logger.h
        Utils/Logger/LoggersImpl/ColorConsoleLogger.h
        Utils/Logger/LoggersImpl/ColorConsoleLogger.cpp

        Utils/Logger/Enums.h
        Utils/Logger/Enums.cpp
        Utils/Logger/LoggerService.h
        Utils/Logger/LoggerService.cpp

        Utils/Macros/PropertyMacro.h

        Utils/Math/MathTypes.h
        Utils/Math/PointI.h
        Utils/Math/PointI.cpp
        Utils/Math/RectangleF.h
        Utils/Math/RectangleF.cpp
        Utils/Math/RectangleI.h
        Utils/Math/RectangleI.cpp

        Utils/File.h
        Utils/File.cpp
        Utils/BackgroundTask.h
        Utils/BackgroundTask.cpp
        Utils/GameHandler.h
        Utils/GameHandler.cpp
        Utils/SimpleCSV.h
        Utils/SimpleCSV.cpp
        Utils/StringUtils.h
        Utils/StringUtils.cpp
        Utils/Timer.h
        Utils/Timer.cpp
    )

    
include_directories(
    ${GLM_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${FREETYPE_INCLUDE_DIRS}
    ${SOIL_INCLUDE_PATH}
    ${SIMPLE_INI_SRC}
    ${PUGI_XML_SRC}
)

add_library(Engine STATIC ${ENGINE_SOURCE_FILES} ${SIMPLE_INI_SRC} ${PUGI_XML_SRC})
