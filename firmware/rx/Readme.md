
# RX Firmware

This folder is reserved for the NavCore RX receiver/control-board firmware.

The RX firmware runs on the STM32G431-based NavCore RX board.

## RX responsibilities

The RX board:

- Receives commands over LoRa
- Reads GPS data
- Reads IMU data
- Controls ESC PWM outputs
- Controls servo PWM outputs
- Reads battery voltage
- Controls light outputs
- Sends telemetry back to the TX/controller

## Current public release status

The full RX firmware project is not included in the first public release.

A cleaned and documented RX firmware release is planned after the public documentation and demo material are complete.

For now, see:

- `firmware/examples/bait-boat-reference/`
- `docs/04-radio-protocol.md`
- `docs/05-firmware-architecture.md`
- `docs/06-getting-started.md`
