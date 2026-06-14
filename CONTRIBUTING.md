# Contributing to NavCore RX

Thank you for your interest in NavCore RX.

NavCore RX is an open-source STM32-based wireless control board for small robotics and RC vehicle experiments. The goal is to build a clear, documented, and useful platform for students, researchers, makers, and embedded developers.

## Ways to contribute

You can contribute by:

* Reporting hardware or firmware issues
* Improving documentation
* Suggesting new application examples
* Testing the board in real projects
* Sharing demo videos or build logs
* Improving firmware structure
* Adding wiring diagrams or tutorials
* Reviewing pinout, protocol, or safety documentation

## Before opening an issue

Please include as much detail as possible:

* Board revision
* Firmware version or commit
* Power supply used
* Radio module used
* GPS/IMU status
* Steps to reproduce the issue
* Photos, logs, or screenshots if available

## Firmware contributions

Firmware contributions should keep the project structure clear:

* Core drivers should remain reusable
* Vehicle-specific behavior should stay in the application layer
* Avoid hardcoding values that should belong in `config.h`
* Keep code readable and documented
* Test changes before opening a pull request

## Documentation contributions

Documentation is a major part of this project.

Good documentation contributions include:

* Clear wiring instructions
* Pinout corrections
* Setup steps
* Troubleshooting notes
* Diagrams
* Real-world testing notes
* Limitations and warnings

## Application examples

NavCore RX may support different robotics experiments over time, but each application must be clearly marked as tested, experimental, or planned.

Please do not describe an application as production-ready unless it has been tested on real hardware.

## Pull requests

When submitting a pull request:

1. Describe what changed
2. Explain why the change is useful
3. Mention whether it was tested on hardware
4. Include photos, logs, or demo videos when relevant

## Project status

NavCore RX is an active development project. Some features are tested, while others are experimental.

Current tested areas include:

* STM32G431 firmware bring-up
* GPS telemetry
* IMU sensing
* LoRa TX/RX communication
* ESC PWM output
* Servo PWM output
* Battery monitoring
* Bait-boat reference firmware

Experimental areas include:

* Autonomous RTH navigation
* Waypoint navigation
* Vehicle-specific PID control
* Drone, rover, and balancing robot application layers

## Code of conduct

Be respectful, constructive, and honest.

This project is intended to help people learn, build, test, and improve open robotics hardware.
