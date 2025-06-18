#pragma once
#include "common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_http_client.h"


#define URL_MAX_LEN 64
#define BUFFER_SIZE 256
#define MAX_READ_SIZE 4096
#define MAPBOX_KEY CONFIG_MAPBOX_KEY

esp_err_t init_http_client();

typedef enum {
    ADDRESS_INIT,
    ADDRESS_UPDATE,
    ADDRESS_WEEKLY
} CURL_TYPES;

typedef struct {
    char url[URL_MAX_LEN];
    CURL_TYPES type
} curl_payload;

