#include <Arduino.h>
#include <SoftwareSerial.h>

struct SensorData {
  // BPM-280
  float temperature;
  float pressure;
  float altitude;
  // MPU-6050
  float accX;
  float accY;
  float accZ;
  float gyroX;
  float gyroY;
  float gyroZ;
  // GPS
  float latitude;
  float longitude;
  float altitudeGPS;
  float speed;
  float course;
};

SoftwareSerial loraSerial(2, 3); // RX, TX

SensorData data;

void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
}

void loop() {
  if (loraSerial.available() >= sizeof(SensorData)) {
    loraSerial.readBytes((uint8_t *)&data, sizeof(SensorData));
    Serial.write((uint8_t *)&data, sizeof(SensorData));
    // Serial.print("Temperature: ");
    // Serial.print(data.temperature);
    // Serial.print(" | Voltage: ");
    // Serial.print(data.pressure);
    // Serial.print(" | Altitude: ");
    // Serial.println(data.altitude);
    // Serial.print("AccX: ");
    // Serial.print(data.accX);
    // Serial.print(" | AccY: ");
    // Serial.print(data.accY);
    // Serial.print(" | AccZ: ");
    // Serial.print(data.accZ);
    // Serial.print(" | GyroX: ");
    // Serial.print(data.gyroX);
    // Serial.print(" | GyroY: ");
    // Serial.print(data.gyroY);
    // Serial.print(" | GyroZ: ");
    // Serial.println(data.gyroZ);
    // Serial.print("Latitude: ");
    // Serial.print(data.latitude);
    // Serial.print(" | Longitude: ");
    // Serial.print(data.longitude);
    // Serial.print(" | AltitudeGPS: ");
    // Serial.print(data.altitudeGPS);
    // Serial.print(" | Speed: ");
    // Serial.print(data.speed);
    // Serial.print(" | Course: ");
    // Serial.println(data.course);
    // Serial.println("------------------------------------------------");
  }
}
