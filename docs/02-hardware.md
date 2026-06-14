# Hardware Overview

## Main components

| Component | Part | Interface | Purpose |
|---|---|---|---|
| MCU | STM32G431CBT6 | — | 170 MHz Cortex-M4, runs firmware |
| IMU | ICM-20948 | I2C | Accelerometer, gyroscope, temperature |
| Magnetometer | AK09916 | Internal via ICM-20948 | Magnetic heading |
| GPS | LC86GLAMD | UART | Position, speed, course, satellites, HDOP |
| Radio | E220-900T22D | UART | LoRa command and telemetry link |
| ESC outputs | PA8 / PA9 | PWM | Left and right motor control |
| Servo outputs | PA0 / PA10 | PWM | Two servo channels |
| Battery ADC | PB1 | ADC | Battery voltage monitoring |
| Light outputs | PA1 / PB5 | GPIO/MOSFET | Switched outputs |
