# WiFi Helper - ESP32 WiFi Component

A sample ESP-IDF project demonstrating a reusable WiFi helper component for ESP32 devices. This project simplifies WiFi initialization, connection management, and event handling.

## Overview

The `wifi_helper` component provides a simplified interface for managing WiFi connectivity on ESP32 devices using the ESP-IDF framework. It handles:

- WiFi stack initialization
- Connection to WiFi networks (SSID/password)
- Event handling (connection, disconnection, IP acquisition)
- Callback registration for WiFi events
- Graceful shutdown and cleanup

## Project Structure

```
wifi_helper/
├── components/
│   └── wifi_helper/              # Reusable WiFi helper component
│       ├── include/
│       │   └── wifi_helper.h      # Public API
│       ├── wifi_helper.c          # Implementation
│       ├── CMakeLists.txt
│       └── Kconfig
├── main/
│   ├── main.c                     # Example application
│   ├── CMakeLists.txt
│   └── Kconfig
├── CMakeLists.txt
├── sdkconfig                      # SDK configuration
└── README.md
```

## Features

### WiFi Helper Component

The component provides the following functionality:

#### Initialization
- **`wifi_helper_init()`** - Initializes the WiFi stack, TCP/IP network, event system, and NVS (Non-Volatile Storage)

#### Connection Management
- **`wifi_helper_connect(ssid, password)`** - Connects to a WiFi network using provided credentials
- **`wifi_helper_disconnect()`** - Disconnects from the current WiFi network
- **`wifi_helper_deinit()`** - Cleans up and deinitializes the WiFi stack

#### Event Handling
- **`wifi_helper_register_on_got_ip_callback(callback)`** - Registers a callback function to be invoked when the device acquires an IP address

### Event Support

The component automatically handles the following WiFi events:

| Event | Description |
|-------|-------------|
| `WIFI_EVENT_WIFI_READY` | WiFi ready |
| `WIFI_EVENT_STA_START` | WiFi STA mode started |
| `WIFI_EVENT_STA_CONNECTED` | Connected to AP |
| `WIFI_EVENT_STA_DISCONNECTED` | Disconnected from AP |
| `IP_EVENT_STA_GOT_IP` | Got IPv4 address |
| `IP_EVENT_GOT_IP6` | Got IPv6 address |

Connection retry logic is included with a maximum of 3 retry attempts.

## Usage Example

Here's a basic example of how to use the WiFi helper component:

```c
#include "esp_log.h"
#include "wifi_helper.h"

static const char *TAG = "wifi_example";

/**
 * Callback function called when WiFi gets an IP address
 */
static void on_wifi_got_ip(void)
{
    ESP_LOGI(TAG, "WiFi connected, IP acquired");
}

void app_main(void)
{
    // Initialize WiFi
    ESP_ERROR_CHECK(wifi_helper_init());
    
    // Register callback
    ESP_ERROR_CHECK(wifi_helper_register_on_got_ip_callback(on_wifi_got_ip));
    
    // Connect to WiFi
    ESP_ERROR_CHECK(wifi_helper_connect(CONFIG_WIFI_HELPER_SSID, CONFIG_WIFI_HELPER_PASSWORD));
}
```

## Configuration

The component uses Kconfig for WiFi credentials. Configure via:

```bash
idf.py menuconfig
```

Navigate to `Component Config > WiFi Helper` to set:
- `WIFI_HELPER_SSID` - Your WiFi network SSID
- `WIFI_HELPER_PASSWORD` - Your WiFi password

## Building and Flashing

### Prerequisites

- ESP-IDF installed and configured
- ESP32 board connected via USB

### Build

```bash
idf.py build
```

### Flash

```bash
idf.py flash
```

### Monitor

```bash
idf.py monitor
```

### Build, Flash, and Monitor

```bash
idf.py build flash monitor
```

## API Reference

### `esp_err_t wifi_helper_init(void)`

Initializes the WiFi stack and related ESP-IDF components.

**Returns:** `ESP_OK` on success, error code otherwise

---

### `esp_err_t wifi_helper_connect(char* wifi_ssid, char* wifi_password)`

Connects to a WiFi network.

**Parameters:**
- `wifi_ssid` - SSID of the WiFi network
- `wifi_password` - Password for the WiFi network

**Returns:** `ESP_OK` on success, error code otherwise

---

### `esp_err_t wifi_helper_disconnect(void)`

Disconnects from the current WiFi network.

**Returns:** `ESP_OK` on success, error code otherwise

---

### `esp_err_t wifi_helper_deinit(void)`

Deinitializes and cleans up the WiFi stack.

**Returns:** `ESP_OK` on success, error code otherwise

---

### `esp_err_t wifi_helper_register_on_got_ip_callback(wifi_event_callback_t callback)`

Registers a callback to be invoked when the device acquires an IP address.

**Parameters:**
- `callback` - Function pointer with signature `void (*)(void)`

**Returns:** `ESP_OK` on success

---

## Implementation Details

### Event Handling

The component uses FreeRTOS event groups to track WiFi connectivity state:
- `WIFI_CONNECTED_BIT` - Set when IP is acquired
- `WIFI_FAIL_BIT` - Set when connection fails after retries

### Security

- Default authentication mode: `WIFI_AUTH_WPA2_PSK`
- Power saving: Disabled (`WIFI_PS_NONE`)
- Storage mode: RAM only (`WIFI_STORAGE_RAM`) - credentials not persisted to flash

### Retry Logic

Maximum 3 connection retry attempts are performed before failing.

## Notes

This is a **sample project** designed to demonstrate WiFi connectivity patterns and best practices for ESP-IDF development. It can be used as a starting point for IoT projects requiring WiFi connectivity.

## License

This project is provided as-is for educational and reference purposes.
