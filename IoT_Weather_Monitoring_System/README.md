# IoT Weather Monitoring System

An IoT-based weather monitoring system using ESP8266 NodeMCU, DHT22 sensor, BMP280 sensor, and Blynk cloud platform for real-time environmental monitoring.

---

## Features

- Real-time temperature monitoring
- Real-time humidity monitoring
- Atmospheric pressure monitoring
- WiFi-enabled IoT system
- Remote monitoring using Blynk mobile app
- Live sensor data visualization
- Serial monitor debugging support

---

## Components Used

- ESP8266 NodeMCU
- DHT22 Temperature and Humidity Sensor
- BMP280 Pressure Sensor
- Breadboard
- Jumper Wires
- WiFi Connection

---

## Technologies Used

- Arduino IDE
- Embedded C++
- Blynk IoT Platform
- I2C Communication
- WiFi Networking

---

## Circuit Connections

### DHT22 Connections

| DHT22 Pin | NodeMCU Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | D1 |

### BMP280 Connections

| BMP280 Pin | NodeMCU Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | D2 |
| SCL | D3 |

---

## Blynk Configuration

Create the following datastreams in Blynk:

| Virtual Pin | Parameter |
|---|---|
| V0 | Temperature |
| V1 | Humidity |
| V2 | Pressure |

Add Gauge widgets for:
- Temperature
- Humidity
- Pressure

---

## Working Principle

1. DHT22 sensor measures temperature and humidity.
2. BMP280 sensor measures atmospheric pressure.
3. ESP8266 reads sensor data.
4. Sensor values are transmitted to Blynk cloud through WiFi.
5. Users can monitor environmental data remotely using the Blynk mobile application.

---

## Serial Monitor Output

```text
Temperature: 29.10 °C
Humidity: 65.40 %
Pressure: 1008.25 hPa
------------------------
```

---

## Applications

- Smart Weather Station
- Environmental Monitoring
- Industrial Monitoring
- IoT Learning Projects
- Smart Agriculture
- Climate Observation Systems

---

## Future Improvements

- Add rainfall sensor
- Add air quality monitoring
- Add OLED display
- Add cloud data logging
- Add weather forecasting system
- Add email/mobile alerts

---

## Libraries Required

Install the following libraries from Arduino IDE Library Manager:

- Blynk
- DHT Sensor Library
- Adafruit BMP280 Library
- Adafruit Unified Sensor

---

## Author

Abhijeet Tatade

---

## License

This project is open-source and available for educational purposes.