#include <AppImplementations\WindowApp.h>
#include "TestGameHandler.h"
int main(int argc, char* argv[])
{
    // TODO replace EmptyGameHandler with concrete game implementation

    App* app = new WindowApp(new TestGameHandler(), "DD", "DDD");
    app->initialize();
    if (app->get_isInitialized())
    {
        app->run();
        if (app->get_isRunning() == false)
        {
            app->exit();
        }
    }
    delete app;
    return 0;
}