#include <Wire.h>
#include <MPU6050.h>

#define ENA   5
#define IN1   2
#define IN2   3
#define ENB   6
#define IN3   4
#define IN4   7

float Kp = 10.0;
float Ki = 0.0;
float Kd = 0.0;
float targetAngle = 0.0;

float motorPower = 0;
float prevError = 0;
float errorSum = 0;
float currentAngle = 0;
float prevAngle = 0;

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  if (mpu.testConnection()) {
    Serial.println("MPU6050 is connected!");
  } else {
    Serial.println("MPU6050 not connected. Check wiring!");
  }
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float accAngle = atan2(ay, az) * RAD_TO_DEG;

  float gyroRate = gx / 131.0;
  float gyroAngle = gyroRate * 0.01;

  currentAngle = 0.98 * (prevAngle + gyroAngle) + 0.02 * accAngle;

  float error = targetAngle - currentAngle;
  errorSum += error;
  errorSum = constrain(errorSum, -300, 300);

  float dError = error - prevError;
  motorPower = Kp * error + Ki * errorSum + Kd * dError;

  motorPower = constrain(motorPower, -255, 255);

  if (motorPower > 0) {
    analogWrite(ENA, abs(motorPower));
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, abs(motorPower));
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (motorPower < 0) {
    analogWrite(ENA, abs(motorPower));
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    analogWrite(ENB, abs(motorPower));
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  prevAngle = currentAngle;
  prevError = error;

  Serial.print("Current Angle: ");
  Serial.print(currentAngle);
  Serial.print("\tError: ");
  Serial.print(error);
  Serial.print("\tMotor Power: ");
  Serial.println(motorPower);

  delay(10);
}