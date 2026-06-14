# NavCore RX Overview

NavCore RX is an STM32-based wireless control board for small robotics and RC vehicle experiments.

It combines the common building blocks needed in many field robotics projects:

* Microcontroller
* GPS receiver
* 9-axis IMU
* LoRa telemetry radio
* ESC PWM outputs
* Servo PWM outputs
* Battery monitoring
* Switched light/load outputs
* Reference firmware

The purpose of NavCore RX is not to replace advanced autopilot systems. Instead, it provides a simpler, open, documented control platform for small vehicle experiments where users need GPS, IMU, radio, and actuator control on one board.

## Public positioning

NavCore RX is best described as:

> An open-source STM32 wireless control board for students, researchers, and makers building small GPS-enabled robotics and RC vehicle experiments.

## Current reference application

The current tested reference application is a bait-boat control system.

This application demonstrates:

* Dual ESC differential drive
* Servo bait-drop mechanism
* GPS telemetry
* Home-position averaging
* IMU-based tilt and safety detection
* LoRa TX/RX control link
* Battery monitoring
* Command acknowledgement and retry handling

## What NavCore RX is good for

NavCore RX is suitable as a starting point for:

* RC boats
* Bait boats
* Small ground rovers
* Hovercraft experiments
* Field telemetry prototypes
* University robotics projects
* Sensor-fusion learning
* GPS/IMU/radio integration experiments

## What NavCore RX is not yet

NavCore RX is not currently presented as:

* A finished commercial autopilot
* A plug-and-play drone flight controller
* A certified safety-critical system
* A production-ready autonomous navigation stack
* A finished consumer bait boat product

Autonomous RTH and waypoint navigation are planned/experimental and should be validated per application before use.

## Design philosophy

NavCore RX follows a simple philosophy:

1. Keep the hardware compact and understandable.
2. Use common interfaces such as UART, I2C, PWM, and ADC.
3. Keep the radio protocol readable using ASCII messages.
4. Separate reusable hardware drivers from application-specific vehicle logic.
5. Document the system clearly so others can learn from it and build on it.

