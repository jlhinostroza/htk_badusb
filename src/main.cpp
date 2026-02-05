#include "core/system_init.h"
#include "app/app_controller.h"

AppController app;

/*#include "core/platform_hal.h"

#include "core/hardware_init.h"
#include "core/system_init.h"
#include "core/mode_manager.h"

#include "services/usb_service.h"
#include "services/comm_service.h"
#include "services/storage_service.h"

#include "drivers/button_driver.h"

#include "utils/logger.h"
*/
void setup()
{

    System_Init();
    app.begin();
/*
    Log_Init();

    while (!Serial);
    Log_Info("Booting firmware...");

    // Inicializar hardware base
    Hardware_Init();
    //System_Init();

    //ModeManager_SetMode(MODE_NORMAL);

    ModeManager modeManager;
    modeManager.ModeInit();
    
    Log_Info("System ready");*/
}

void loop()
{

    app.update();

/*    StorageService_Update();
delay(10); // pequeño respiro al CPU
*/
}