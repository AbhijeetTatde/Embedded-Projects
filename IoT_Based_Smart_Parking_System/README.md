# IoT Based Smart Parking System

An IoT-based smart parking system using ESP32, IR sensors, GPS module, LCD display, and Blynk IoT platform.

## Features

- Real-time parking slot monitoring
- Live GPS location tracking
- LCD display for slot status
- Blynk cloud integration
- Mobile notifications when parking is full
- WiFi-enabled monitoring system

## Components Used

- ESP32
- IR Sensors (2)
- GPS Module (NEO-6M)
- 16x2 I2C LCD
- Jumper Wires
- Breadboard
- WiFi Network

## Technologies Used

- Arduino IDE
- Blynk IoT
- Embedded C++
- ESP32 WiFi

## Pin Configuration

| Component | ESP32 Pin |
|----------|-----------|
| IR Sensor 1 | GPIO 32 |
| IR Sensor 2 | GPIO 33 |
| GPS RX | GPIO 16 |
| GPS TX | GPIO 17 |
| LCD SDA | SDA |
| LCD SCL | SCL |

## Blynk Virtual Pins

| Virtual Pin | Function |
|-------------|----------|
| V1 | Latitude |
| V2 | Longitude |
| V3 | Slot 1 Status |
| V4 | Slot 2 Status |

## Working

1. IR sensors detect vehicle presence.
2. ESP32 reads sensor data.
3. Parking status is displayed on LCD.
4. GPS module sends live location.
5. Data is uploaded to Blynk cloud.
6. Notification is sent when all slots are occupied.

## Output

- Displays parking availability on LCD
- Shows live GPS coordinates in Blynk app
- Sends mobile notification when parking is full

## Future Improvements

- Add more parking slots
- Add payment integration
- Add camera-based vehicle detection
- Create web dashboard
- Add automatic gate control

## Author

Abhijeet Tatade