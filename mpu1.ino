#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo;  // Create servo object to control a servo

MPU6050 mpu6050(Wire);  // Create MPU6050 object

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());  // Access the X angle value
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());  // Missing semicolon fixed
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());  // Missing semicolon fixed

  // Ensure servo position stays within 0-180 degrees
  int servoPos = constrain(map(mpu6050.getAngleX(), -90, 90, 0, 180), 0, 180);
  myservo.write(servoPos);

  delay(15);
}
