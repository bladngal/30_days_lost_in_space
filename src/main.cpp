// src/main.cpp
#include <Arduino.h>
#include "blink.h"

int LED10 = 10;
int LED11 = 11;
int LED12 = 12;
int Switch1 = 2;
int Switch2 = 3;
int Switch3 = 4;

void setup() {
    pinMode(LED10, OUTPUT);
    pinMode(Switch1, INPUT);  
    pinMode(LED11, OUTPUT);
    pinMode(Switch2, INPUT);
    pinMode(LED12, OUTPUT);
    pinMode(Switch3, INPUT);
}

void loop() {
  //Switch number 1
  if(digitalRead(Switch1) == 1){
    digitalWrite(LED10, HIGH); //send 5V aka ON
  }
  else{
    digitalWrite(LED10, LOW); //turn it off aka GROUND
  }
  //Switch number 2
  if(digitalRead(Switch2) == 1){
    digitalWrite(LED11, HIGH); //send 5V aka ON
  }
  else{
    digitalWrite(LED11, LOW); //turn it off aka GROUND
  }
  //Switch number 3
  if(digitalRead(Switch3) == 1){
    digitalWrite(LED12, HIGH); //send 5V aka ON
  }
  else{
    digitalWrite(LED12, LOW); //turn it off aka GROUND
  }
  
  
    Serial.println("Loop complete");
}