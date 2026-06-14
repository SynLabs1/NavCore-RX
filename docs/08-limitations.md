# Limitations

NavCore RX is an active open hardware development project. This page documents current limitations honestly.

## Not a finished autopilot

NavCore RX is not currently a finished plug-and-play autopilot. It provides a tested hardware and firmware foundation for small robotics experiments.

## RTH and waypoint navigation

Return-to-home and waypoint commands exist in the protocol, but autonomous navigation should be treated as experimental until fully implemented and field-tested.

## Magnetometer calibration

Magnetometer heading requires installation-specific calibration. Motors, batteries, and wiring can affect magnetic readings.

## Vehicle-specific tuning required

Each vehicle needs its own tuning for:

- Motor start pulses
- Servo positions
- IMU safety thresholds
- Control mapping
- Navigation behavior
- Power system layout

## Safety

Do not use NavCore RX in safety-critical or high-risk systems without independent validation, failsafes, and field testing.
