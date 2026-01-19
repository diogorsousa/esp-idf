# Buzzer Test

A simple ESP32 project that generates a tone using the LEDC (LED PWM Controller) peripheral connected to a buzzer.

## Configuration

The following parameters can be configured via `idf.py menuconfig` under "Buzzer Configuration":

- **Buzzer GPIO Pin**: GPIO pin number connected to the buzzer (default: 21)
- **Buzzer Frequency**: PWM frequency in Hz (default: 1046, range: 20-40000)
- **Buzzer Duty Cycle**: Duty cycle percentage (default: 50%, range: 0-100)

## Building and Flashing

```bash
# Configure the project (optional)
idf.py menuconfig

# Build the project
idf.py build

# Flash to ESP32-S3
idf.py flash
```

## How It Works

The project configures the LEDC peripheral to generate a PWM signal at the specified frequency and duty cycle. When the device boots, it plays a beep for 500ms and then stops.

**Hardware Details:**
- LEDC Timer: TIMER_0 (Low Speed Mode)
- LEDC Channel: CHANNEL_0
- Duty Resolution: 8-bit (0-255)
