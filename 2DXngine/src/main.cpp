#include "TestGameHandlerWithScenes.h"
#include "TestGameHandler.h"
#include "DefinedTypes.h"
#include <AppImplementations\Builder\AppBuilder.h>

int main(int argc, char* argv[])
{
    AppBuilder::createForPlatrorm(AppPlatform::WINDOWS)
        ->withHandler(new TestGameHandlerWithScenes())
        ->buildAndRun();
    return 0;
}