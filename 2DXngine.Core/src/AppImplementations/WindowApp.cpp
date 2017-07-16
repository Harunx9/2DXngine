#include "WindowApp.h"
#include <gl\glew.h>
#include "../Services/ServiceLocator.h"
#include "SDLEvents/SDLEventsMapperService.h"
#include "../ContentManagement/ContentManagerService.h"
#include "../Input/InputService.h"
#include "../Audio/MusicService.h"
#include "../Audio/SoundService.h"
#include "../Config/ConfigurationService.h"
#include "../Scenes/SceneManagerService.h"
#include <SDL_mixer.h>
#include <iostream>
#include <windows.h>
#include "../Utils/BackgroundTask.h"

WindowApp::WindowApp(GameHandler* handler,const char* companyName, const char* appName):
    App(handler, companyName, appName)
{
}

WindowApp::~WindowApp()
{
}

void WindowApp::initialize()
{
    this->initDirsIfNotExist();
    this->initAndRegiserConfig();
    
    this->_device = new GraphicDevice();
    this->_isFixedTimeStep = true;
    this->_timeStep = 1.f / 30.f;
    this->_timer = new Timer();

    this->_device->initialize(
        this->_cfgService->get_graphics(),
        this->_appName);

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        return;

    if (this->_device->get_isInitialized() && this->_game)
    {
        this->_game->set_device(this->_device);
        buildServiceContrainer();
        this->_game->regiserUserServices();
        this->_game->initialize();
        ServiceLocator::initialize();
        this->_isInitialized = true;
        this->_isRunning = true;
    }
}

void WindowApp::run()
{
    SDL_Event event;
    auto sdlEventMapper = ServiceLocator::get<SDLEventsMapperService>("SDLEventsMapperService");
    float accumulator = 0.0f;
    this->_timer->timerStart();
    while (this->get_isRunning())
    {
        float deltaTime = this->_timer->getDeltaTime();
        std::cout << deltaTime << std::endl;
        accumulator += deltaTime;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                this->_isRunning = false;
            }
            else
            {
                sdlEventMapper->map(&event);
            }
        }

        while (accumulator >= this->_timeStep)
        {
            
            this->_game->update(deltaTime);
            accumulator -= this->_timeStep;
        }

        if (TaskPool::get().anyTasksLeft())
        {
            TaskPool::get().update();
        }

        this->_game->draw(deltaTime);
    }
}

void WindowApp::exit()
{
    Mix_CloseAudio();
    SDL_Quit();
}

void WindowApp::initDirsIfNotExist()
{
#if RELEASE
    wchar_t* pref = (wchar_t*) SDL_GetPrefPath(this->_companyName, this->_appName);
    CreateDirectory(pref, NULL);
#endif
}

void WindowApp::buildServiceContrainer()
{
    ServiceLocator::registerService(new SDLEventsMapperService());
    ServiceLocator::registerService(new ContentManagerService());
    ServiceLocator::registerService(new InputService());
    ServiceLocator::registerService(new SoundService());
    ServiceLocator::registerService(new MusicService());
    ServiceLocator::registerService(new SceneManagerService());
}

void WindowApp::initAndRegiserConfig()
{
    this->_cfgService = new ConfigurationService(this->_appName, this->_companyName);
    this->_cfgService->baseInitialize();
    ServiceLocator::registerService(this->_cfgService);
}
