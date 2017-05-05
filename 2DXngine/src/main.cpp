#include <AppImplementations\WindowApp.h>
#include "TestGameHandler.h"
int main(int argc, char* argv[])
{
    // TODO replace EmptyGameHandler with concrete game implementation

    App* app = new WindowApp(new TestGameHandler());
    app->initialize();
    if (app->getIsInitialized())
    {
        app->run();
        if (app->getIsRunning() == false)
        {
            app->exit();
        }
    }
    delete app;
    return 0;
}