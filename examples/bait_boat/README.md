# Bait Boat Reference Application

This folder contains a simplified public reference example showing how NavCore RX can be used as the control board for a small bait boat or surface vehicle.

The example demonstrates the application-layer logic used on top of the NavCore RX core firmware services.

## What this example demonstrates

- Dual ESC differential drive
- Servo bait-drop sequence
- GPS telemetry
- Home-position averaging concept
- IMU-based safety states
- Battery monitoring
- LoRa command and telemetry flow
- TX/RX command acknowledgement concept

## Important status note

This is a public reference example, not the full production firmware release.

The purpose of this folder is to show how an application can be structured on NavCore RX while keeping the reusable low-level drivers separated from vehicle-specific logic.

## Hardware used

- NavCore RX board
- STM32G431CBT6
- ICM-20948 IMU
- LC86GLAMD GPS
- E220-900T22D LoRa radio
- Two ESC PWM outputs
- Two servo PWM outputs
- Battery ADC input
- Light MOSFET outputs

## Tested reference features

- GPS telemetry
- IMU sensing
- ESC PWM output
- Servo output
- Battery monitoring
- LoRa communication
- Basic bait-boat command flow

## Experimental / not production-ready

- Autonomous return-to-home navigation
- Waypoint navigation
- Fully tuned field navigation
- Vehicle-independent autopilot behavior

See the main project limitations page before using this in a real vehicle.
