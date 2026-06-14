<p align="center">
  <img src="assets/navcore-rx-hero.png" alt="NavCore RX" width="850">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/MCU-STM32G431-blue">
  <img src="https://img.shields.io/badge/GPS-LC86GLAMD-green">
  <img src="https://img.shields.io/badge/IMU-ICM--20948-orange">
  <img src="https://img.shields.io/badge/Radio-LoRa%20900MHz-purple">
  <img src="https://img.shields.io/badge/Status-Active%20Development-yellow">
</p>




# NavCore RX

**Open-source STM32 wireless control board for small robotics and RC vehicle experiments.**

NavCore RX is a compact control board built around an STM32G431 microcontroller, GPS, 9-axis IMU, LoRa telemetry, ESC PWM outputs, servo outputs, battery monitoring, and a tested bait-boat reference firmware.

It is designed for students, researchers, makers, and embedded developers who want a ready hardware foundation for small GPS-enabled robotics vehicles without starting every project from sensor integration, radio communication, and motor-control firmware.

> Current status: NavCore RX is a tested hardware and firmware reference platform. GPS telemetry, IMU sensing, LoRa communication, ESC PWM, servo output, battery monitoring, and the bait-boat reference firmware are tested. Autonomous RTH and waypoint navigation are experimental and not presented as production-ready yet.

---

## Why NavCore RX exists

Most small robotics projects spend weeks integrating the same foundation before the actual application begins:

* Microcontroller bring-up
* GPS parsing
* IMU reading
* Radio communication
* Motor PWM generation
* Servo control
* Battery monitoring
* Telemetry protocol
* Safety states and command handling

NavCore RX brings these building blocks together on one tested board, so the user can focus on the vehicle behavior instead of rebuilding the foundation from scratch.

---

## Hardware at a glance

| Block           | Part                     | Purpose                                                |
| --------------- | ------------------------ | ------------------------------------------------------ |
| MCU             | STM32G431CBT6            | 170 MHz Cortex-M4 control processor                    |
| IMU             | ICM-20948                | Accelerometer, gyroscope, temperature                  |
| Compass         | AK09916 inside ICM-20948 | Magnetic heading                                       |
| GPS             | LC86GLAMD                | Position, speed, course, satellite count, HDOP         |
| Radio           | E220-900T22D             | 900 MHz LoRa telemetry and command link                |
| Motor outputs   | 2x ESC PWM               | Differential motor control                             |
| Servo outputs   | 2x PWM                   | Bait drop, rudder, pump, gimbal, or custom mechanism   |
| Battery monitor | ADC input                | Battery voltage measurement                            |
| Light outputs   | MOSFET outputs           | Front/rear light control or low-current switched loads |

---

## What is tested today

* STM32G431 firmware bring-up
* GPS NMEA parsing
* IMU pitch/roll/heading readout
* LoRa TX/RX communication
* ASCII command and telemetry protocol
* ESC PWM outputs
* Servo PWM outputs
* Battery voltage monitoring
* Front/rear light MOSFET outputs
* Bait-boat reference firmware
* TX/RX command acknowledgement and retry logic

---

## What is experimental

These features are under development and should not be treated as production-ready yet:

* Autonomous return-to-home navigation
* Waypoint navigation
* Vehicle-specific PID control
* Drone attitude-control firmware
* Balancing robot firmware
* Multi-vehicle application examples beyond the bait-boat reference

---

## Reference application: bait boat

The first tested reference application is a bait-boat control system.

The reference firmware demonstrates:

* Differential ESC motor control
* Servo bait-drop sequence
* GPS telemetry
* Home-position averaging
* IMU-based tilt and safety states
* Battery monitoring
* LoRa command and telemetry link
* TX/RX command confirmation and retry handling

This reference application is used as the starting point for future boat, rover, hovercraft, and research-vehicle examples.

---

## Firmware structure

The firmware is organized into two layers:

```text
APPLICATION LAYER
Vehicle-specific logic:
- safety rules
- servo behavior
- motor mapping
- timing constants
- application states

CORE LIBRARY
Reusable hardware services:
- GPS parser
- IMU reader
- radio communication
- motor PWM
- servo PWM
- battery reading
- telemetry packets
```

The goal is to keep low-level hardware drivers reusable while allowing each application to change only the behavior layer.

---

## Documentation

Start here:

* [Overview](docs/01-overview.md)
* [Hardware Overview](docs/02-hardware.md)
* [Pinout](docs/03-pinout.md)
* [Radio Protocol](docs/04-radio-protocol.md)
* [Firmware Architecture](docs/05-firmware-architecture.md)
* [Demo Status](docs/07-demo-status.md)
* [Limitations](docs/08-limitations.md)
* [Roadmap](docs/09-roadmap.md)

---

## Demo videos

Feature demo videos will be added here:

* Board bring-up
* LoRa TX/RX communication
* GPS telemetry
* IMU pitch/roll/heading
* ESC PWM output
* Servo output sequence
* Battery monitoring
* Firmware architecture walkthrough

---

## Who this is for

NavCore RX is intended for:

* Robotics students
* University project teams
* Embedded systems learners
* RC vehicle experimenters
* Research prototypes
* Makers building GPS-enabled vehicles
* Developers who want a starting platform for custom control firmware

It is not currently marketed as a finished consumer product or a certified autopilot.

---

## Roadmap

Short term:

* Publish public documentation
* Add clean firmware examples
* Add feature demo videos
* Add wiring diagrams
* Add getting-started guide

Mid term:

* Improve application-layer examples
* Add rover/surface-vehicle example
* Improve magnetometer calibration guide
* Add simulation or bench-test navigation examples

Long term:

* Autonomous RTH navigation
* Waypoint navigation
* Small production batch
* Tindie / Crowd Supply launch evaluation

---

## License

Firmware license: MIT License
Hardware license: CERN Open Hardware License, planned for public hardware release

---

## Project status

NavCore RX is an active Synvertex Engineering open hardware project.

Website: https://synvertexengineering.com
