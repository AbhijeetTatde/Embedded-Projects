// ==== BLYNK CONFIG ====
#define BLYNK_TEMPLATE_ID "TMPL3cax_drCN"
#define BLYNK_TEMPLATE_NAME "IoT Based parking"
#define BLYNK_AUTH_TOKEN "FX8VXyOC4kDdAVi3put3utpo4-ghXoF7"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// ==== WiFi Credentials ====
char ssid[] = "Chhaya"; // ⚠️ Remove space if it gives error
char pass[] = "123456789";

// ==== LCD Setup ====
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust if I2C address is different

// ==== GPS Setup ====
TinyGPSPlus gps;
HardwareSerial gpsSerial(1); // Serial1 on ESP32
#define GPS_RX 16  // ESP32 receives from GPS TX
#define GPS_TX 17  // ESP32 TX (optional)

// ==== IR Sensor Pins ====
#define IR1 32
#define IR2 33

BlynkTimer timer;
bool notificationSent = false; // Prevent spamming notifications

// ==== Function: Send GPS + Parking Status ====
void sendToBlynk() {
  // GPS Data
  if (gps.location.isUpdated()) {
    float lat = gps.location.lat();
    float lng = gps.location.lng();

    Blynk.virtualWrite(V1, lat);  // Latitude
    Blynk.virtualWrite(V2, lng);  // Longitude

    Serial.print("Lat: ");
    Serial.print(lat);
    Serial.print(" | Lng: ");
    Serial.println(lng);
  }

  // IR Sensor Data
  bool slot1 = digitalRead(IR1) == LOW; // LOW = object detected
  bool slot2 = digitalRead(IR2) == LOW;

  String s1 = slot1 ? "Occupied" : "Free";
  String s2 = slot2 ? "Occupied" : "Free";

  Blynk.virtualWrite(V3, s1);  // Slot 1 status
  Blynk.virtualWrite(V4, s2);  // Slot 2 status

  // LCD Update
  lcd.setCursor(0, 0);
  lcd.print("S1:");
  lcd.print(s1);
  lcd.setCursor(9, 0);
  lcd.print("S2:");
  lcd.print(s2);

  // 🔔 Notification Logic
  if (slot1 && slot2 && !notificationSent) {
    Blynk.logEvent("all_slots_full", "All parking slots are currently occupied.");
    notificationSent = true;  // Avoid sending repeatedly
  } else if (!slot1 || !slot2) {
    // Reset notification flag when any slot becomes free
    notificationSent = false;
  }
}

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000L, sendToBlynk); // Every 5 sec
}

void loop() {
  Blynk.run();
  timer.run();

  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }
}
