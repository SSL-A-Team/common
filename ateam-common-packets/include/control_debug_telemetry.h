/**
 * @file control_debug_telemetry.h
 * @author Will Stuckey
 * @brief definition for controls debug telemetry data type
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "common.h"

typedef struct MotorDebugTelemetry {
    float wheel_setpoint;
    float wheel_velocity;
    float wheel_torque;
} MotorDebugTelemetry;
assert_size(MotorDebugTelemetry, 12);

typedef struct ControlDebugTelemetry {
    MotorDebugTelemetry motor_fl;
    MotorDebugTelemetry motor_bl;
    MotorDebugTelemetry motor_br;
    MotorDebugTelemetry motor_fr;
    /// 48 bytes

    float imu_gyro[3];  // rad/s
    float imu_accel[3];  // m/s^2
    // 24 bytes

    float commanded_body_velocity[3];  // commanded body velocity from the AI
    float clamped_commanded_body_velocity[3];  // commanded body velocity from the AI after the local (firmware) velocity and acceleration limits are imposed
    float cgkf_body_velocity_state_estimate[3];  // CG Kalman Filter estiamted body velocity
    float body_velocity_u[3];  // body velocity PID output "u"
    /// 48 bytes

    float wheel_velocity_u[4];  // wheel velocities calculated from transform of body velocities after control policy
    float wheel_velocity_clamped_u[4];  // wheel velocities after control policy clamped for local acceleration limits
    /// 32 bytes
} ControlDebugTelemetry;
assert_size(ControlDebugTelemetry, 48 + 24 + 48 + 32);
