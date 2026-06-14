# Demo Status

This page tracks what has been tested and what is still experimental.

## Tested

| Feature | Status | Notes |
|---|---|---|
| STM32G431 bring-up | Tested | Firmware runs on board |
| LoRa radio link | Tested | TX/RX ASCII protocol |
| GPS parsing | Tested | NMEA parsing and telemetry |
| IMU readout | Tested | Pitch, roll, heading data |
| ESC PWM outputs | Tested | Two 50 Hz PWM outputs |
| Servo outputs | Tested | Two servo PWM outputs |
| Battery ADC | Tested | Battery voltage monitoring |
| Light MOSFET outputs | Tested | GPIO-controlled switched outputs |
| Bait-boat reference firmware | Tested | Reference application |

## Experimental

| Feature | Status | Notes |
|---|---|---|
| RTH navigation | Experimental | Command path exists, navigation logic under development |
| WP_GO navigation | Experimental | Coordinates can be received, autonomous navigation still under development |
| Drone application | Research only | Not tested as flight controller |
| Balancing robot application | Research only | Requires custom control loop |
| Rover application | Planned | Needs application-specific testing |
