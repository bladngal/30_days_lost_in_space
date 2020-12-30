#include <Arduino.h>

#define onboard 13

void blink(int ms) {
    digitalWrite(onboard, LOW);
    delay(ms);
    digitalWrite(onboard, HIGH);
    delay(ms);
}