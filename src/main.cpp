// src/main.cpp
#include <Arduino.h>
#include "constants.h"
#include "rotary_move.h";

// RGB LED pins
int red = RED_PIN;
int green = GREEN_PIN;
int blue = BLUE_PIN;
int sensorPin = A0;
int sensorValue = 0;
int blueValue = 255;
int rotaryALastState;
int rotaryMoveDirection;
 
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

  // begin setup for rotary encoder
  pinMode (ROTARY_A,INPUT);
  pinMode (ROTARY_B,INPUT);
  pinMode (ROTARY_PUSH,INPUT);

  // Read the initial state for rotary encoder
  rotaryALastState = digitalRead(ROTARY_A);
}
 
void loop() {
  sensorValue = analogRead(sensorPin);

  //more sensor value = more blue light

  int blueLightValue = getBlueLightValue(sensorValue);
  int redLightValue = 255 - blueLightValue;
  //RGB_color(redLightValue, 255,blueLightValue ); // Blue
  RGB_color(255, 255, 255);
  delay(50);

  /*************************
  // BEGIN ROTARY ENCODER
  *************************/
    Serial.println("Rotary direction ----");
    Serial.println(rotaryALastState);
    rotaryMoveDirection = getRotaryMove(rotaryALastState);
    delay(200);
    rotaryALastState = digitalRead(ROTARY_A);
}
 
