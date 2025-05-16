#include <Arduino.h>
#include <SoftwareSerial.h>

// const int ledPin = 13; // the number of the LED pin
// char incomingByte; // for incoming serial data

// void setup() {
//   Serial.begin(9600);
//   pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
// }

// void loop() {
//   if (Serial.available() > 0) {
//     Serial.println("Serial.available() > 0");
//     incomingByte = Serial.read();
//     if (incomingByte == 'H') {
//       Serial.print('H');
//       Serial.println(incomingByte);
//       digitalWrite(ledPin, HIGH); // turn the LED on
//     } else if (incomingByte == 'L') {
//       Serial.print('L');
//       Serial.println(incomingByte);
//       digitalWrite(ledPin, LOW); // turn the LED off
//     }
//   }
// }

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

SensorData receivedData;

void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600);
}

void loop() {
  if (loraSerial.available() >= sizeof(SensorData)) {
    loraSerial.readBytes((uint8_t *)&receivedData, sizeof(SensorData));
    Serial.print("Temperature: ");
    Serial.print(receivedData.temperature);
    Serial.print(" | Voltage: ");
    Serial.print(receivedData.pressure);
    Serial.print(" | Altitude: ");
    Serial.println(receivedData.altitude);
    Serial.print("AccX: ");
    Serial.print(receivedData.accX);
    Serial.print(" | AccY: ");
    Serial.print(receivedData.accY);
    Serial.print(" | AccZ: ");
    Serial.print(receivedData.accZ);
    Serial.print(" | GyroX: ");
    Serial.print(receivedData.gyroX);
    Serial.print(" | GyroY: ");
    Serial.print(receivedData.gyroY);
    Serial.print(" | GyroZ: ");
    Serial.println(receivedData.gyroZ);
    Serial.print("Latitude: ");
    Serial.print(receivedData.latitude);
    Serial.print(" | Longitude: ");
    Serial.print(receivedData.longitude);
    Serial.print(" | AltitudeGPS: ");
    Serial.print(receivedData.altitudeGPS);
    Serial.print(" | Speed: ");
    Serial.print(receivedData.speed);
    Serial.print(" | Course: ");
    Serial.println(receivedData.course);
    Serial.println("------------------------------------------------");

  }
}
