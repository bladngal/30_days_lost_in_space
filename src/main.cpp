// src/main.cpp
#include <Arduino.h>
#include "blink.h"

int LED = 12;
int Switch1 = 2;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(Switch1, INPUT);  
}

void loop() {
  if(digitalRead(Switch1) == 1){
    digitalWrite(LED, HIGH); //send 5V aka ON
  }
  else{
    digitalWrite(LED, LOW); //turn it off aka GROUND
  }
  
  
    Serial.println("Loop complete");
}