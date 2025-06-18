#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include <string.h>
#include "sdkconfig.h"




#define EXAMPLE_ESP_WIFI_SSID      "F829A6"
#define EXAMPLE_ESP_WIFI_PASS      "42T7692B01813"
#define EXAMPLE_ESP_MAXIMUM_RETRY  200
#define FS_BASE      "/sdcard"

#define GENERAL_ERROR 0x8000 
#define BAD_HTTP_RESPONSE (GENERAL_ERROR + 1)
#define RESPONSE_TOO_LARGE (GENERAL_ERROR + 2)
