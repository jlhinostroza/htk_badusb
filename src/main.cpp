#include "core/system_init.h"
#include "app/app_controller.h"
#include "core/hardware_init.h"

AppController app;

/*#include "core/platform_hal.h"


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
}

void loop()
{
    Hardware_Update();
    app.update();

/*    StorageService_Update();
delay(10); // pequeño respiro al CPU
*/
}