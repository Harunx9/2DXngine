#include "TestImplementation/TestGameHandlerWithScenes.h"
#include "TestImplementation/TestGameHandler.h"
#include "TestImplementation/DefinedTypes.h"
#include <AppImplementations/Builder/AppBuilder.h>

int main(int argc, char* argv[])
{
    AppBuilder::createForPlatrorm(AppPlatform::WINDOWS)
        ->withHandler(new TestGameHandlerWithScenes())
        ->buildAndRun();
    return 0;
}