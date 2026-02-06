#include "core/system_init.h"
#include "app/app_controller.h"
#include "core/hardware_init.h"

AppController app;

void setup()
{
    System_Init();
    app.begin();
}

void loop()
{
    Hardware_Update();
    app.update();
}