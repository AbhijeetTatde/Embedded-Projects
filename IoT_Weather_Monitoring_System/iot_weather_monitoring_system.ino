#define BLYNK_TEMPLATE_ID "TMPL3cax_drCN"
#define BLYNK_TEMPLATE_NAME "IoT Weather Monitoring"
#define BLYNK_AUTH_TOKEN "FX8VXyOC4kDdAVi3put3utpo4-ghXoF7"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

char ssid[] = "Chhaya";
char pass[] = "123456789";

#define DHT_PIN D1
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

Adafruit_BMP280 bmp;

BlynkTimer timer;

void sendSensorData() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float pressure = bmp.readPressure() / 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.println("------------------------");

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, pressure);
}

void setup() {

  Serial.begin(115200);

  dht.begin();

  if (!bmp.begin()) {
    Serial.println("BMP280 sensor not found!");
    while (1);
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensorData);

  Serial.println("IoT Weather Monitoring System Started");
}

void loop() {

  Blynk.run();
  timer.run();
}