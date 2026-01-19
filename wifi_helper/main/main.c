#include "esp_log.h"
#include "wifi_helper.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

char* TAG = "wifi_example";

/**
 * @brief Callback function called when WiFi gets an IP address
 */
static void on_wifi_got_ip(void)
{
    ESP_LOGI(TAG, "WiFi connected, IP acquired");
}

void app_main(void)
{
    ESP_ERROR_CHECK(wifi_helper_init());
    ESP_ERROR_CHECK(wifi_helper_register_on_got_ip_callback(on_wifi_got_ip));
    ESP_ERROR_CHECK(wifi_helper_connect(CONFIG_WIFI_HELPER_SSID, CONFIG_WIFI_HELPER_PASSWORD));
}
