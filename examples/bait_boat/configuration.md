#ifndef CONFIG_EXAMPLE_H
#define CONFIG_EXAMPLE_H

/*
 * NavCore RX - Bait Boat Reference Configuration
 *
 * This is a simplified public example.
 * Tune these values for your own vehicle, ESCs, servos, and safety limits.
 */

/* Motor PWM */
#define ESC_MIN_PULSE_US        1000
#define ESC_MAX_PULSE_US        2000

#define MOTOR_LEFT_START_US     1200
#define MOTOR_RIGHT_START_US    1200

/* Servo PWM */
#define SERVO_MIN_PULSE_US      500
#define SERVO_CENTER_PULSE_US   1500
#define SERVO_MAX_PULSE_US      2500

/* Servo bait-drop sequence */
static const int servo_positions_us[] = {
    500,    /* Step 0: closed/reset */
    1500,   /* Step 1: partial open */
    2500,   /* Step 2: fully open */
    1500    /* Step 3: return center */
};

/* Timing */
#define IMU_READ_INTERVAL_MS        100
#define GPS_SEND_INTERVAL_MS        2000
#define STATUS_SEND_INTERVAL_MS     3000
#define BATTERY_READ_INTERVAL_MS    30000

/* Safety thresholds - tune per vehicle */
#define BOAT_ROLL_WARNING_DEG       25.0f
#define BOAT_ROLL_CAPSIZE_DEG       60.0f
#define BOAT_PITCH_WARNING_DEG      25.0f
#define BOAT_PITCH_CAPSIZE_DEG      60.0f

/* Radio command retry */
#define CMD_MAX_RETRIES             3
#define CMD_RETRY_INTERVAL_MS       200

#endif
