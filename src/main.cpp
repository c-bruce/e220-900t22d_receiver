#include <Arduino.h>

const int ledPin = 13; // the number of the LED pin
char incomingByte; // for incoming serial data

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
}

void loop() {
  if (Serial.available() > 0) {
    Serial.println("Serial.available() > 0");
    incomingByte = Serial.read();
    if (incomingByte == 'H') {
      Serial.print('H');
      Serial.println(incomingByte);
      digitalWrite(ledPin, HIGH); // turn the LED on
    } else if (incomingByte == 'L') {
      Serial.print('L');
      Serial.println(incomingByte);
      digitalWrite(ledPin, LOW); // turn the LED off
    }
  }
}
