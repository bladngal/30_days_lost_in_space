// src/main.cpp
#include <Arduino.h>
#include "blink.h"
//#define onboard 13

int LED = 12;
int tripWirePin = 8;
int buzzerPin = 7;

void setup() {
    //pinMode(LED, OUTPUT);

    Serial.begin(9600);
    
}


void loop() {
  
  //system is intact and untripped
  if(digitalRead(tripWirePin) == 1) {
    Serial.println("System Armed");
  }
else {
  tone(buzzerPin, 250, 500);
  blink(LED, 1000);
  Serial.println("INTRUDER ALERT!!");
  noTone(buzzerPin);
}
    Serial.println("Loop complete");
}