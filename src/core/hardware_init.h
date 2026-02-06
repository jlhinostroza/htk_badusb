#pragma once

#include "../drivers/led_driver.h"
#include "../drivers/button_driver.h"
#include "../drivers/sd_driver.h"

extern LedDriver statusLed;
extern ButtonDriver modeButton;
extern SDDriver sdCard;


void Hardware_Init();
void Hardware_Update();
