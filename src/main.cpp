// src/main.cpp
#include <Arduino.h>

int red = 11;
int green = 10;
int blue = 9;
 
void RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
} 

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
 
void loop() {
  RGB_color(125, 0, 0); // Red
  delay(500);
  RGB_color(0, 125, 0); // Green
  delay(500);
  RGB_color(0, 0, 125); // Blue
  delay(500);
  RGB_color(0, 125, 125); // yellow
  delay(500);
  RGB_color(125, 0, 125); // purple
  delay(500);
  RGB_color(125, 125, 125); // white
  delay(500);
}
 
