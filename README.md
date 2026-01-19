# ESP-IDF Examples

A collection of ESP-IDF example projects for ESP32 microcontrollers.

## Overview

This repository contains various examples demonstrating different features and peripherals of ESP32 development using the ESP-IDF framework. Each example is self-contained with its own documentation and build configuration.

## Examples

### [buzzer-test](buzzer-test/)
Buzzer test example demonstrating basic PWM control and audio output.

### [wifi-helper](wifi-helper/)
WiFi helper component example for ESP32 network connectivity.

## Prerequisites

- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html) installed and configured
- ESP32 development board
- USB cable for flashing and serial communication

## Getting Started

Each example project can be built and flashed independently. Navigate to the specific example directory and follow these steps:

```bash
# Navigate to an example
cd buzzer-test

# Configure the project (optional)
idf.py menuconfig

# Build the project
idf.py build

# Flash to your ESP32
idf.py -p PORT flash monitor
```

Replace `PORT` with your ESP32's serial port (e.g., `/dev/ttyUSB0` on Linux, `COM3` on Windows, or `/dev/cu.usbserial-*` on macOS).

## License

See individual example directories for specific license information.
