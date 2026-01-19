#pragma once

#include "esp_err.h"
#include "esp_log.h"

#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_wifi.h"

#include "freertos/FreeRTOS.h"

/**
 * @brief Callback function type for WiFi events
 */
typedef void (*wifi_event_callback_t)(void);

esp_err_t wifi_helper_init(void);

esp_err_t wifi_helper_connect(char* wifi_ssid, char* wifi_password);

esp_err_t wifi_helper_disconnect(void);

esp_err_t wifi_helper_deinit(void);

/**
 * @brief Register a callback to be invoked when WiFi gets an IP
 * @param callback Function pointer to be called on WiFi IP event
 * @return ESP_OK on success
 */
esp_err_t wifi_helper_register_on_got_ip_callback(wifi_event_callback_t callback);