#include "http_client.h"

uint8_t permitted_addresses = 15;
QueueHandle_t url_queue = NULL;
esp_http_client_handle_t client = NULL;
char *curl_tag = "CURL STATUS";

static int http_client_task(void *param) {
  char received[URL_MAX_LEN];
  while (1) {
    if (xQueueReceive(url_queue, &received, portMAX_DELAY) == pdPASS) {
      esp_err_t rc = esp_http_client_set_url(client, received);
      if (rc != ESP_OK) {
        ESP_LOGE("CLIENT ERROR", "Could not update the url for curl request");
      }
      int res = esp_http_client_get_status_code(client);
      if (res < 200 || res >= 300) {
        ESP_LOGE(curl_tag, "curl response for %s is bad. Recevied status %d",
                 received, res);
        return BAD_HTTP_RESPONSE;
      }
      int res_len = esp_http_client_get_content_length(client);
      if (res_len > MAX_READ_SIZE) {
        ESP_LOGE(curl_tag, "curl response for %s is too large", received);
        return RESPONSE_TOO_LARGE;
      }
      char buffer[BUFFER_SIZE + 1];
      char response =
    }
  }
}

esp_err_t init_http_client() {

  esp_http_client_config_t config = {
      .url = "https://placeholder.com", // dummy url
  };

  client = esp_http_client_init(&config);

  url_queue = xQueueCreate(permitted_addresses, URL_MAX_LEN);
  while (url_queue == NULL && permitted_addresses > 0) {
    ESP_LOGE("QUEUE", "Failed to create queue with size %d",
             permitted_addresses);
    permitted_addresses -= 5;
    url_queue = xQueueCreate(permitted_addresses, URL_MAX_LEN);
  }

  if (url_queue == NULL) {
    ESP_LOGE("QUEUE", "Queue creation ultimately failed");
    return ESP_ERR_NO_MEM;
  }

  const char *url1 = "San Diego";

  curl_payload payload = {
    .url = 
  }



  char msg[URL_MAX_LEN];
  strncpy(msg, url1, URL_MAX_LEN);
  xQueueSend(url_queue, msg, portMAX_DELAY);

  xTaskCreate(http_client_task, "http_client_task", 4096, NULL, 5, NULL);
  return ESP_OK;
}
