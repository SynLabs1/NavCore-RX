# Radio Protocol

NavCore RX uses a simple ASCII command protocol over the LoRa UART link.

Messages are newline-terminated text strings.

## TX to RX commands

| Command | Example | Description |
|---|---|---|
| Motor | `M:65,72` | Set left motor to 65%, right motor to 72% |
| Stop | `STOP` | Stop motors |
| Servo step | `SERVO_STEP:2` | Move servo to step 2 |
| Light on | `LIGHT_ON` | Turn light outputs on |
| Light off | `LIGHT_OFF` | Turn light outputs off |
| Set home | `SET_HOME` | Start GPS home averaging |
| RTH on | `RTH_ON` | Experimental return-to-home command |
| RTH off | `RTH_OFF` | Disable RTH |
| Waypoint go | `WP_GO:...` | Experimental waypoint command |

## RX to TX messages

| Message | Example | Description |
|---|---|---|
| GPS packet | `G:...` | GPS, battery, distance, heading telemetry |
| Status | `S:82,9,2` | Battery, satellites, GPS fix |
| Alert | `A:1,1800,120,30,230` | IMU/safety alert |
| Home set | `H:...` | Home coordinates stored |
| OK | `OK` | Command acknowledged |
| Bait confirm | `BAIT:2` | Servo step confirmed |
| Stop confirm | `STP` | Motor stop confirmed |
