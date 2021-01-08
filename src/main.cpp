// src/main.cpp
#include <Arduino.h>

int sensorPin = A0;
int onboardLED = 13;
int sensorValue = 0; //holder value
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel =0;

void PrintBatteryPercentage() {
  Serial.print(((double)batteryLevel / (double)batteryCapacity)*100);
  Serial.println("%");
}

void setup() {
  Serial.begin(9600);  
  pinMode(onboardLED, OUTPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorPin;

  if(batteryLevel >= batteryCapacity) {
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity;
  }
  else {
    PrintBatteryPercentage();
  }

    delay(50);
}