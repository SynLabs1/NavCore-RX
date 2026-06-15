# TX Firmware

This folder is reserved for the optional NavCore TX/controller firmware.

The TX firmware is used by the reference bait-boat system to send commands and display telemetry.

## TX responsibilities

The TX/controller can:

- Read joystick input
- Send motor commands
- Send servo commands
- Send light commands
- Send home/RTH/waypoint commands
- Receive telemetry from RX
- Display GPS/status/battery/link information

## Current public release status

The full TX firmware project is not included in the first public release.

A cleaned and documented TX firmware release is planned later.

NavCore RX can also be tested using direct UART/radio commands without publishing the full TX firmware immediately.
