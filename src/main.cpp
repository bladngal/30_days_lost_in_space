// src/main.cpp
#include <Arduino.h>
#include "blink.h"
//#define onboard 13

int LED = 12;

void setup() {
    pinMode(LED, OUTPUT);
    //Serial.begin(9600);
    
}


void loop() {
  
  blink(LED, 1000);
    Serial.println("Loop complete");
}