# NavCore RX Firmware

This folder contains the public firmware structure and reference examples for NavCore RX.

NavCore RX firmware is organized around two layers:

```text
APPLICATION LAYER
Vehicle-specific behavior:
- safety logic
- servo behavior
- motor mapping
- timing constants
- command handling
- application states

CORE LIBRARY
Reusable hardware services:
- GPS parsing
- IMU reading
- LoRa radio communication
- ESC PWM output
- Servo PWM output
- Battery reading
- Telemetry packet generation
