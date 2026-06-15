/*
 * NavCore RX - Bait Boat Reference Application
 *
 * This file shows the application-layer structure for a small surface vehicle.
 * It is intentionally simplified for public documentation.
 */

#include "config.example.h"

/* Example application state */
static int servo_step = 0;
static int motor_left_percent = 0;
static int motor_right_percent = 0;

/*
 * Called when a motor command is received from the TX controller.
 * Example command: M:65,72
 */
void App_HandleMotorCommand(int left_percent, int right_percent)
{
    motor_left_percent = left_percent;
    motor_right_percent = right_percent;

    /* Core library function */
    Motor_Set(motor_left_percent, motor_right_percent);
}

/*
 * Called when a servo step command is received.
 * Example command: SERVO_STEP:2
 */
void App_HandleServoStepCommand(int requested_step)
{
    int expected_next = (servo_step + 1) % 4;

    /*
     * Idempotent step handling:
     * If a duplicate command arrives because of radio retry,
     * do not move the servo twice.
     */
    if (requested_step == expected_next) {
        servo_step = requested_step;
        Servo_SetPulse(1, servo_positions_us[servo_step]);
    }

    /*
     * Reply with the actual current step.
     * Example response: BAIT:2
     */
    Radio_SendBaitConfirm(servo_step);
}

/*
 * Called when light command is received.
 */
void App_HandleLightCommand(bool lights_on)
{
    if (lights_on) {
        Light_Set(true);
        Radio_SendOK();
    } else {
        Light_Set(false);
        Radio_SendOK();
    }
}

/*
 * Application-specific IMU safety logic.
 * This should be tuned for the final vehicle.
 */
void IMU_CheckSafety(void)
{
    float roll = imu_get_roll();
    float pitch = imu_get_pitch();

    if (roll > BOAT_ROLL_CAPSIZE_DEG || roll < -BOAT_ROLL_CAPSIZE_DEG ||
        pitch > BOAT_PITCH_CAPSIZE_DEG || pitch < -BOAT_PITCH_CAPSIZE_DEG) {
        App_SetStatus(STATUS_CAPSIZE);
        Radio_SendAlert();
        Motor_Stop();
        return;
    }

    if (roll > BOAT_ROLL_WARNING_DEG || roll < -BOAT_ROLL_WARNING_DEG ||
        pitch > BOAT_PITCH_WARNING_DEG || pitch < -BOAT_PITCH_WARNING_DEG) {
        App_SetStatus(STATUS_TILT_WARNING);
        Radio_SendAlert();
        return;
    }

    App_SetStatus(STATUS_OK);
}

/*
 * Simplified main application loop.
 * Real firmware uses non-blocking timing with HAL_GetTick().
 */
void App_BaitBoatLoop(void)
{
    Radio_ProcessIncomingCommands();

    if (TimeElapsed(IMU_READ_INTERVAL_MS)) {
        IMU_ReadAll();
        IMU_Process();
        IMU_CheckSafety();
    }

    if (GPS_HasNewSentence()) {
        GPS_Process();
    }

    if (TimeElapsed(GPS_SEND_INTERVAL_MS)) {
        SendGPSToTX();
    }

    if (TimeElapsed(BATTERY_READ_INTERVAL_MS)) {
        ReadBattery();
    }
}
