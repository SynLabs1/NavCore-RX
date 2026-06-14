# Firmware Architecture

The firmware is split into two layers.

```text
APPLICATION LAYER
Vehicle-specific behavior:
- safety logic
- servo behavior
- motor mapping
- timing constants
- application state machine

        calls

CORE LIBRARY
Reusable hardware services:
- IMU_ReadAll()
- GPS_Poll()
- E220_Send()
- Motor_Set()
- ReadBattery()
- FilterDistance()

        runs on

HARDWARE
STM32G431 + ICM-20948 + LC86GLAMD + E220 radio
