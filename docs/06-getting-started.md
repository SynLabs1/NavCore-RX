# Getting Started with NavCore RX

This guide helps you bring up NavCore RX for the first time and verify the main hardware blocks one by one.

NavCore RX is currently a development/reference platform. The goal of this guide is not to make a finished autonomous vehicle immediately. The goal is to confirm that the board, sensors, radio link, PWM outputs, and reference firmware are working correctly.

---

## 1. What you need

### Hardware

* NavCore RX board
* Compatible TX/controller board or USB/UART test setup
* 5V regulated power supply or ESC BEC
* E220-900T22D radio module, or compatible UART radio module
* GPS antenna / clear outdoor GPS view
* Servo motor for PWM output test
* ESC or logic analyzer/oscilloscope for motor PWM test
* ST-Link programmer/debugger
* Common ground between all connected devices

### Software

* STM32CubeIDE
* STM32CubeProgrammer
* STM32CubeMX, if modifying the generated configuration
* Serial terminal or SWO/ITM debug console
* Git

---

## 2. Power warning

NavCore RX must be powered from a regulated 5V supply.

Do not connect the board directly to a LiPo/main battery unless a proper regulator or BEC is used.

Motors and ESCs require their own power path. The NavCore RX board only provides PWM control signals; it does not power the motors.

All connected devices must share a common ground.

---

## 3. First power-up checklist

Before flashing firmware, visually inspect:

* No solder bridges
* Correct power polarity
* Radio module inserted correctly
* GPS connected correctly
* Servo/ESC signal pins connected to the correct outputs
* Common ground connected between board, ESC, servo power, and test equipment

Power the board from a regulated 5V source.

Expected result:

* Board powers normally
* 3.3V rail is stable
* MCU can be detected by ST-Link

---

## 4. Flash the firmware

1. Connect ST-Link to the SWD pins.
2. Open the firmware project in STM32CubeIDE.
3. Select the correct STM32G431 target.
4. Build the project.
5. Flash the firmware using STM32CubeIDE or STM32CubeProgrammer.
6. Open the debug console or serial/SWO output.

Expected boot messages may include checks for:

* MCU startup
* IMU status
* Radio status
* GPS status
* PWM initialization
* Battery ADC initialization

---

## 5. Verify IMU

The ICM-20948 IMU is connected over I2C.

Move or tilt the board slowly and confirm that pitch and roll values change.

Expected result:

* Pitch changes when the board is tilted forward/backward
* Roll changes when the board is tilted left/right
* Heading values may change, but magnetometer heading requires installation-specific calibration

Important note:

Magnetometer readings are affected by motors, batteries, wires, and metal objects. Final heading calibration should be done after the board is mounted in its real installation position.

---

## 6. Verify GPS

Place the board outdoors or near a window with a clear view of the sky.

Cold start can take up to 60 seconds or more.

Check for:

* GPS fix status
* Satellite count
* Latitude/longitude
* HDOP
* Speed/course, if moving

Expected result:

* GPS fix becomes valid after lock
* Satellite count increases
* Coordinates become available
* HDOP improves as signal quality improves

---

## 7. Verify radio link

NavCore RX uses an ASCII text protocol over a UART radio link.

The reference radio module is E220-900T22D, but other compatible transparent UART radio modules may be used if configured correctly.

Basic command examples:

```text
M:0,0
LIGHT_ON
LIGHT_OFF
SERVO_STEP:1
SET_HOME
```

Expected responses may include:

```text
OK
STP
BAIT:1
S:82,9,2
G:...
```

Make sure both TX and RX radios use the same:

* UART baud rate
* Channel
* Air data rate
* Addressing mode, if used
* Transparent transmission mode

---

## 8. Verify ESC PWM outputs

NavCore RX provides two ESC PWM outputs:

| Output    | Pin            | Purpose         |
| --------- | -------------- | --------------- |
| Left ESC  | PA8 / TIM1 CH1 | Left motor PWM  |
| Right ESC | PA9 / TIM1 CH2 | Right motor PWM |

Use a logic analyzer, oscilloscope, or ESC for testing.

Expected signal:

* 50 Hz PWM
* Idle pulse around 1000 µs
* Throttle range typically around 1000–2000 µs

Start with motors disconnected if possible and verify PWM first using a logic analyzer or oscilloscope.

Then connect ESCs carefully and test at low throttle.

---

## 9. Verify servo outputs

NavCore RX provides two servo PWM outputs:

| Output  | Pin             | Purpose        |
| ------- | --------------- | -------------- |
| Servo 1 | PA0 / TIM2 CH1  | Servo output 1 |
| Servo 2 | PA10 / TIM1 CH3 | Servo output 2 |

The bait-boat reference firmware uses a stepped servo sequence.

Example sequence:

```text
Step 0: closed / reset
Step 1: partial open
Step 2: fully open
Step 3: return centre
Step 0: closed / reset
```

Test command:

```text
SERVO_STEP:1
SERVO_STEP:2
SERVO_STEP:3
SERVO_STEP:0
```

Expected result:

* Servo moves one step per valid command
* Duplicate retry commands should not cause unsafe double movement in the reference protocol

---

## 10. Verify battery monitoring

Battery voltage is read using the ADC input.

Check that the firmware reports battery voltage or battery percentage.

If the reported value is incorrect:

* Verify resistor divider values
* Verify ADC pin connection
* Verify ground reference
* Verify battery scale constants in firmware

Do not exceed the safe ADC input voltage range.

---

## 11. Verify light outputs

NavCore RX includes two MOSFET-controlled outputs:

| Output      | Pin | Control        |
| ----------- | --- | -------------- |
| Front light | PA1 | GPIO HIGH = ON |
| Rear light  | PB5 | GPIO HIGH = ON |

Test commands:

```text
LIGHT_ON
LIGHT_OFF
```

Expected result:

* Both light outputs switch according to the command
* RX replies with `OK`

---

## 12. Suggested first demo order

For first public testing, verify features in this order:

1. Board power-up
2. Firmware flash
3. IMU readout
4. GPS telemetry
5. Radio link
6. Servo output
7. ESC PWM output
8. Battery monitoring
9. Light outputs
10. Full TX/RX reference demo

This order makes debugging easier because each feature builds on the previous one.

---

## 13. What is tested

The following areas are part of the current tested reference platform:

* STM32G431 firmware bring-up
* ICM-20948 IMU readout
* GPS NMEA parsing
* E220 LoRa communication
* ASCII command and telemetry protocol
* ESC PWM outputs
* Servo PWM outputs
* Battery monitoring
* Light output control
* Bait-boat reference firmware

---

## 14. What is experimental

The following areas are experimental or under development:

* Autonomous return-to-home navigation
* Waypoint navigation
* Vehicle-specific PID control
* Drone flight-control application
* Balancing robot application
* Rover application examples beyond bench/reference testing

Do not treat experimental features as production-ready without your own validation and field testing.

---

## 15. Next steps

After confirming board bring-up:

* Read the [Hardware Overview](02-hardware.md)
* Read the [Pinout](03-pinout.md)
* Read the [Radio Protocol](04-radio-protocol.md)
* Read the [Firmware Architecture](05-firmware-architecture.md)
* Review the [Demo Status](07-demo-status.md)
* Review the [Limitations](08-limitations.md)
* Check the [Roadmap](09-roadmap.md)

---

## 16. Safety note

NavCore RX is intended for development, education, prototyping, and research.

Do not use it in safety-critical systems without independent validation, failsafes, field testing, and application-specific review.

