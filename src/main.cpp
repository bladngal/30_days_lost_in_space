// Code written by Alexander Eschenauer for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure
 
#include <Keypad.h>
 
const byte ROWS = 4;
const byte COLS = 4;

int buzzer = 10;  
 
char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
// byte rowPins[ROWS] = {5, 4, 3, 2};
// byte colPins[COLS] = {2, 3, 4, 5};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7 ,8 ,9};

int tones[ROWS][COLS] = {
    {31, 93, 147, 208},
    {247, 311, 370, 440},
    {523, 587, 698, 880},
    {1397, 2637, 3729, 4978}
};
 
// Using the Keypad.h Library, we are going to define a custom keypad.
// In order to do that, it needs to know the following:
// What the keys are (a 2D Array of characters (char)),
// what pins are being used (2 thru 9),
// how many rows there are (4), and how many columns (4).
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);
 
void setup(){
  Serial.begin(9600); // Begin monitoring via the serial monitor
}
 
void loop() {
  int toneFreq = 0;
  char customKey = customKeypad.getKey();
  if (customKey) { //if a button is pressed
    Serial.print(customKey);
    Serial.print(": ");
    for (byte j=0; j<ROWS; j++) {
        for (byte i=0; i<COLS; i++) {
            if (customKey == buttons[j][i]) {
                toneFreq=tones[j][i];
                break;
            }
        }
    }
    tone(buzzer, toneFreq, 500);
    delay(500);
    noTone(buzzer);
  }
}
