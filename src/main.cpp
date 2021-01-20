// Code written by Alexander Eschenauer for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure
#include <Arduino.h>
#include <TM1637Display.h>
// Define the connections pins:
#define CLK 6
#define DIO 5
// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);
// Create array that turns all segments on:
const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
// Create array that turns all segments off:
const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
// You can set the individual segments per digit to spell words or create other symbols:
const uint8_t done[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,          // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
    SEG_C | SEG_E | SEG_G,                          // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G           // E
};

const uint8_t SOS[] = {
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,          // S
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,
    0x00  // S
};

void setup() {
    Serial.begin(9600);  // Begin monitoring via the serial monitor
    display.clear();
    delay(1000);
}

void loop() {
    // Set the brightness:
    display.setBrightness(5);
    // All segments on:
    display.setSegments(data);
    delay(1000);
    display.clear();
    delay(1000);
    // Show counter:
    int i;
    for (i = 0; i <= 10; i++) {
        display.showNumberDec(i);
        delay(50);
    }
    delay(1000);
    display.clear();
    delay(1000);
    display.setSegments(done);
    delay(1000);
    display.clear();
    delay(1000);
    display.setSegments(SOS);
    while (1)
        ;
}
