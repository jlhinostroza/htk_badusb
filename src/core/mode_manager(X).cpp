#include "../core/platform_hal.h"

#include  "../drivers/button_driver.h"
#include "../services/storage_service.h"
#include "../core/system_init.h"
#include "../utils/logger.h"

#include "mode_manager.h"

ModeManager::ModeManager() {
    StorageService_Init();
}

void ModeManager::ModeInit() {
    if (modeButtonRead() == LOW) {
        Log_Info("Booting in MSC mode...");

        if (!StorageService_Available()) {
            Log_Error("Cannot initialize MSC mode: Storage service failed");
        } else {
            Log_Info("MSC mode initialized successfully");
        }
    } else {
        System_Init(); // Inicializa el sistema en modo normal
    }
}
