# NavCore RX Hardware

This folder contains public hardware reference material for the NavCore RX board.

NavCore RX is built around:

- STM32G431CBT6 microcontroller
- ICM-20948 9-axis IMU
- AK09916 magnetometer inside the ICM-20948
- LC86GLAMD GPS module
- E220-900T22D LoRa radio interface
- Two ESC PWM outputs
- Two servo PWM outputs
- Battery voltage monitoring
- Front/rear light MOSFET outputs

## Current public hardware release status

Public now:

- Board photos
- Pinout reference
- Hardware overview
- Block diagrams
- Connector/function descriptions

Planned for later release:

- Full schematic
- PCB source files
- Gerbers
- BOM
- Pick-and-place files
- Manufacturing package

The full manufacturing files are planned for release after the first public validation/beta batch.

## Hardware license

Hardware design files will be released under CERN-OHL-S-2.0 unless otherwise stated.

See:

- [HARDWARE-LICENSE](../HARDWARE-LICENSE)

## Safety note

NavCore RX provides control signals only. Motors, ESCs, servos, and batteries must be wired and powered safely.

The board should be powered from a regulated 5V supply or BEC. Do not power it directly from a LiPo/main battery without regulation.
