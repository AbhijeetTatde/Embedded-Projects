# Self-Balancing Robot using ESP32 and MPU6050

A realtime self-balancing robot developed using the ESP32 microcontroller and MPU6050 gyroscope-accelerometer sensor. The robot maintains vertical balance using PID-based feedback control and realtime motor speed adjustments.

The project focuses on embedded control systems, sensor interfacing, PWM motor control, IMU data processing, and closed-loop balancing algorithms for dynamic stability.

---

# Project Objectives

- Develop a realtime self-balancing robot
- Implement PID-based feedback control
- Interface MPU6050 IMU sensor using I2C communication
- Control DC motors using PWM signals
- Stabilize robot movement using sensor fusion
- Gain hands-on experience with embedded control systems

---

# Features

- ESP32-based embedded firmware
- PID-based balance correction
- Realtime tilt angle calculation
- MPU6050 gyroscope and accelerometer interfacing
- PWM motor speed control
- Bidirectional motor direction control
- I2C communication protocol implementation
- Complementary filter for angle estimation
- Closed-loop balancing system
- Serial debugging support

---

# Hardware Components

| Component | Description |
|---|---|
| ESP32 Development Board | Main microcontroller |
| MPU6050 | Gyroscope + Accelerometer sensor |
| L298N Motor Driver | Dual H-Bridge motor driver |
| DC Gear Motors | Robot movement |
| Robot Chassis | Mechanical frame |
| Wheels | Robot mobility |
| Battery Pack | Power supply |

---

# Software and Tools Used

| Software | Purpose |
|---|---|
| Arduino IDE | Firmware development |
| Embedded C/C++ | Programming language |
| MPU6050 Library | Sensor communication |
| Wire Library | I2C communication |

---

# Pin Configuration

## Motor Driver Connections

| ESP32 Pin | Function |
|---|---|
| GPIO 5 | Left Motor PWM |
| GPIO 2 | Left Motor IN1 |
| GPIO 3 | Left Motor IN2 |
| GPIO 6 | Right Motor PWM |
| GPIO 4 | Right Motor IN3 |
| GPIO 7 | Right Motor IN4 |

---

## MPU6050 Connections

| MPU6050 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | SDA |
| SCL | SCL |

---

# Working Principle

The MPU6050 continuously measures the robot tilt angle using accelerometer and gyroscope data.

The firmware processes sensor readings and calculates the current tilt angle using a complementary filter. A PID controller computes the correction value based on the difference between the current angle and the target vertical angle.

Motor speed and direction are dynamically adjusted to maintain balance.

---

# PID Control System

The robot uses a closed-loop PID controller for balancing.

## PID Equation

Control Output = Kp x Error + Ki x Integral + Kd x Derivative

Where:

- Kp -> Proportional gain
- Ki -> Integral gain
- Kd -> Derivative gain

The PID controller continuously corrects motor movement to reduce tilt error and maintain stability.

---

# Sensor Fusion

A complementary filter combines:

- Accelerometer angle data
- Gyroscope angular velocity

This improves:
- stability
- noise reduction
- angle estimation accuracy

---

# PWM Motor Control

PWM signals are used to regulate motor speed dynamically.

## Motor Actions

| Robot Tilt | Motor Response |
|---|---|
| Falling Forward | Move Forward |
| Falling Backward | Move Backward |
| Balanced | Stop Motors |

Motor direction and speed are continuously updated based on PID output values.

---

# Challenges Faced

- Sensor noise from MPU6050
- Oscillations during balancing
- PID tuning instability
- Motor response delay
- Mechanical center-of-gravity balancing
- Noise filtering for stable angle estimation

---

# Optimizations Performed

- Applied complementary filter for smoother angle estimation
- Tuned PID constants experimentally
- Limited integral wind-up
- Adjusted PWM motor response
- Reduced balancing oscillations
- Improved realtime correction stability

---

# Project Structure

Self-Balancing-Robot/

- code/
- README.md
- block_diagram/

---

# Build Status

- Firmware successfully compiled and uploaded
- Realtime balancing achieved using PID control
- MPU6050 communication verified successfully

---

# Future Improvements

- Encoder feedback integration
- Kalman filter implementation
- Bluetooth telemetry
- Mobile app control
- Advanced PID auto-tuning
- Brushless motor implementation
- STM32-based control system migration

---

# Learning Outcomes

- PID control fundamentals
- Realtime embedded system design
- Sensor interfacing using I2C
- PWM motor control
- Sensor fusion concepts
- IMU data processing
- Closed-loop feedback systems
- Embedded robotics fundamentals

---

# Author

Abhijeet Tatde