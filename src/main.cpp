// src/main.cpp
#include <Arduino.h>

int red = 11;
int green = 10;
int blue = 9;
int sensorPin = A0;
int sensorValue = 0;
int blueValue = 255;
 
void RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
} 

int getBlueLightValue(int sensorValue){
  int blueLightValue = 255; //no blue light
  //I'm calling 500 max on sensor value
  int maxValue = 500;
  double sensorPercentage = (double)sensorValue/(double)maxValue;
  double inversePercentage = 1 - sensorPercentage;
  blueLightValue = inversePercentage * blueLightValue;
  return blueLightValue;
}

void setup() {
  Serial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
 
void loop() {
  sensorValue = analogRead(sensorPin);

  //more sensor value = more blue light

  int blueLightValue = getBlueLightValue(sensorValue);
  int redLightValue = 255 - blueLightValue;
  RGB_color(redLightValue, 255,blueLightValue ); // Blue
  delay(50);
}
 
