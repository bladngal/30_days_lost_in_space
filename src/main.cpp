// src/main.cpp
#include <Arduino.h>
#include "blink.h"
#define onboard 13

void setup() {
    pinMode(onboard, OUTPUT);
    Serial.begin(9600);
}
// void blink(int ms) {
//     digitalWrite(onboard, LOW);
//     delay(ms);
//     digitalWrite(onboard, HIGH);
//     delay(ms);
// }

void pause(int ms) {
    digitalWrite(onboard, LOW);
    delay(ms);
}
void loop() {
  //currently sending SOS
    blink(300);
    blink(300);
    blink(300);
    pause(300);
    
    blink(600);
    blink(600);
    blink(600);
    pause(300);

    blink(300);
    blink(300);
    blink(300);
    pause(300);

    Serial.println("Loop complete");
}