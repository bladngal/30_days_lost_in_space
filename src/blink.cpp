#include <Arduino.h>


void blink(uint8_t pin, int ms) {
    digitalWrite(pin, LOW);
    delay(ms);
    digitalWrite(pin, HIGH);
    delay(ms);
}