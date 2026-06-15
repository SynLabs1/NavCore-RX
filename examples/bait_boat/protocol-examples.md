# Bait Boat Protocol Examples

This page shows example TX ↔ RX messages used by the NavCore RX bait-boat reference application.

The protocol is intentionally simple. Commands and telemetry packets are sent as readable ASCII text over the LoRa UART link.

Each message is a short text string. In the reference firmware, messages are sent over the radio module in transparent UART mode.

---

## 1. Motor command

The TX/controller sends motor commands to the RX board using the `M:` command.

```text
M:left,right
```

Example:

```text
M:65,72
```

Meaning:

| Field       | Value | Meaning                     |
| ----------- | ----: | --------------------------- |
| Left motor  |    65 | Left ESC output set to 65%  |
| Right motor |    72 | Right ESC output set to 72% |

The RX board converts these percentage values into calibrated ESC PWM pulses.

Example behavior:

```text
M:0,0       -> both motors stopped
M:30,30     -> both motors forward at low speed
M:70,70     -> both motors forward at higher speed
M:50,20     -> turn by driving left motor faster than right motor
M:20,50     -> turn by driving right motor faster than left motor
```

---

## 2. Stop command

The stop command immediately stops the motors.

TX sends:

```text
STOP
```

RX response:

```text
STP
```

Meaning:

| Message | Direction | Meaning                |
| ------- | --------- | ---------------------- |
| `STOP`  | TX → RX   | Stop motor outputs     |
| `STP`   | RX → TX   | Stop command confirmed |

---

## 3. Servo bait-drop command

The bait-drop servo uses a step-based command.

TX sends:

```text
SERVO_STEP:n
```

Example:

```text
SERVO_STEP:1
```

The reference bait-drop sequence uses four servo positions:

| Step | Example position | Purpose          |
| ---: | ---------------- | ---------------- |
|    0 | Closed/reset     | Mechanism closed |
|    1 | Partial open     | First movement   |
|    2 | Fully open       | Bait drops       |
|    3 | Return center    | Return movement  |

Example sequence:

```text
SERVO_STEP:1
SERVO_STEP:2
SERVO_STEP:3
SERVO_STEP:0
```

RX response:

```text
BAIT:n
```

Example:

```text
BAIT:2
```

Meaning:

| Message        | Direction | Meaning                |
| -------------- | --------- | ---------------------- |
| `SERVO_STEP:2` | TX → RX   | Request servo step 2   |
| `BAIT:2`       | RX → TX   | Servo is now at step 2 |

The reference protocol uses step confirmation so that duplicate retry messages do not accidentally move the servo twice.

---

## 4. Light commands

The light outputs are controlled using simple ON/OFF commands.

Turn lights on:

```text
LIGHT_ON
```

Expected response:

```text
OK
```

Turn lights off:

```text
LIGHT_OFF
```

Expected response:

```text
OK
```

Meaning:

| Message     | Direction | Meaning               |
| ----------- | --------- | --------------------- |
| `LIGHT_ON`  | TX → RX   | Enable light outputs  |
| `LIGHT_OFF` | TX → RX   | Disable light outputs |
| `OK`        | RX → TX   | Command accepted      |

---

## 5. Set home command

The `SET_HOME` command starts GPS home-position averaging.

TX sends:

```text
SET_HOME
```

Possible RX responses:

```text
AVERAGING
AVG:5/10
H:33,552834,N,73,123456,E
HOME_SET
NO_FIX
```

Meaning:

| Message     | Direction | Meaning                       |
| ----------- | --------- | ----------------------------- |
| `SET_HOME`  | TX → RX   | Start home-position averaging |
| `AVERAGING` | RX → TX   | Home averaging started        |
| `AVG:5/10`  | RX → TX   | 5 of 10 GPS samples collected |
| `H:...`     | RX → TX   | Home coordinates sent         |
| `HOME_SET`  | RX → TX   | Home position stored          |
| `NO_FIX`    | RX → TX   | GPS fix not available yet     |

---

## 6. GPS/status packet without fix

When GPS does not yet have a valid fix, the RX board can send a status packet.

Example:

```text
S:82,9,2
```

Format:

```text
S:battery_percent,satellites,fix
```

Field breakdown:

| Field      | Example | Meaning                |
| ---------- | ------: | ---------------------- |
| Battery    |      82 | Battery level is 82%   |
| Satellites |       9 | 9 satellites detected  |
| Fix        |       2 | GPS fix quality/status |

This allows the TX/controller to show board status even before full GPS telemetry is available.

---

## 7. GPS telemetry packet

When GPS telemetry is available, the RX board sends a `G:` packet.

Example:

```text
G:33,552834,N,73,123456,E,12,2,120,55,82,45,48,1800,15
```

General format:

```text
G:lat_int,lat_frac,lat_dir,lon_int,lon_frac,lon_dir,sats,fix,hdop_x100,speed_x10,battery_percent,distance_m,raw_distance_m,heading_x10,accuracy_x10
```

Field breakdown:

| Field             | Example | Meaning                     |
| ----------------- | ------: | --------------------------- |
| `lat_int`         |      33 | Latitude integer degrees    |
| `lat_frac`        |  552834 | Latitude fractional part    |
| `lat_dir`         |       N | North/South                 |
| `lon_int`         |      73 | Longitude integer degrees   |
| `lon_frac`        |  123456 | Longitude fractional part   |
| `lon_dir`         |       E | East/West                   |
| `sats`            |      12 | Satellites in use           |
| `fix`             |       2 | GPS fix quality             |
| `hdop_x100`       |     120 | HDOP = 1.20                 |
| `speed_x10`       |      55 | Speed = 5.5 km/h            |
| `battery_percent` |      82 | Battery = 82%               |
| `distance_m`      |      45 | Filtered distance from home |
| `raw_distance_m`  |      48 | Raw GPS distance            |
| `heading_x10`     |    1800 | Heading = 180.0 degrees     |
| `accuracy_x10`    |      15 | Estimated accuracy = 1.5 m  |

---

## 8. Alert packet

The RX board can send an alert packet when the IMU safety state changes.

Example:

```text
A:1,1800,120,30,230
```

Format:

```text
A:status,heading_x10,pitch_x10,roll_x10,temp_x10
```

Field breakdown:

| Field       | Example | Meaning                          |
| ----------- | ------: | -------------------------------- |
| Status      |       1 | Application-defined safety state |
| Heading     |    1800 | Heading = 180.0 degrees          |
| Pitch       |     120 | Pitch = 12.0 degrees             |
| Roll        |      30 | Roll = 3.0 degrees               |
| Temperature |     230 | Temperature = 23.0 °C            |

Possible application states can include:

| Status | Meaning      |
| -----: | ------------ |
|      0 | OK           |
|      1 | Tilt warning |
|      2 | Capsize      |
|      3 | Rough water  |
|      4 | Stuck        |

The exact state values may be changed by the application firmware.

---

## 9. Return-to-home command

The protocol includes return-to-home commands.

Enable RTH:

```text
RTH_ON
```

Expected response:

```text
OK
```

Disable RTH:

```text
RTH_OFF
```

Expected response:

```text
OK
```

Important status note:

RTH command handling exists in the protocol, but autonomous navigation should be treated as experimental unless fully implemented and field-tested in the application firmware.

---

## 10. Waypoint command

The protocol includes a waypoint command format.

Example:

```text
WP_GO:33,552834,N,73,123456,E
```

Meaning:

| Field         | Meaning          |
| ------------- | ---------------- |
| `33,552834,N` | Target latitude  |
| `73,123456,E` | Target longitude |

Important status note:

Waypoint command reception can be demonstrated, but waypoint navigation should be treated as experimental until the control logic is implemented and tested in the real vehicle.

---

## 11. Example command flow

A simple bait-boat test sequence may look like this:

```text
TX -> RX: LIGHT_ON
RX -> TX: OK

TX -> RX: M:30,30
RX drives both ESC outputs at low throttle

TX -> RX: SERVO_STEP:1
RX -> TX: BAIT:1

TX -> RX: SERVO_STEP:2
RX -> TX: BAIT:2

TX -> RX: M:0,0
RX -> TX: STP

TX -> RX: LIGHT_OFF
RX -> TX: OK
```

---

## 12. Why ASCII protocol?

The bait-boat reference application uses readable ASCII messages because they are:

* Easy to debug
* Easy to log
* Easy to test from a serial terminal
* Easy to extend
* Easy for students and researchers to understand

This is useful during development because every command can be inspected directly without a binary decoder.

---

## 13. Current status

Tested in the reference platform:

* Motor command format
* Servo step command format
* Light command format
* Status packets
* GPS telemetry packet structure
* Command acknowledgement concept
* Bait-step confirmation concept

Experimental:

* Autonomous RTH behavior
* Waypoint navigation behavior
* Application-specific autopilot logic

This file is intended as a public protocol explanation for the bait-boat reference application, not as a guarantee of production-ready autonomous navigation.

