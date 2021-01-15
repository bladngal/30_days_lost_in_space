// Code written by Alexander Eschenauer for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;

char password[PassLength] = {'0', '0', '0', '0'};

int buzzer = 8;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

char buttons[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// byte rowPins[ROWS] = {5, 4, 3, 2};
// byte colPins[COLS] = {2, 3, 4, 5};

byte rowPins[ROWS] = {5, 4, 3, 2};
//byte colPins[COLS] = {6, 7, 8, 9}; // previous pins
byte colPins[COLS] = {6, 7, 12, 13};

// Using the Keypad.h Library, we are going to define a custom keypad.
// In order to do that, it needs to know the following:
// What the keys are (a 2D Array of characters (char)),
// what pins are being used (2 thru 9),
// how many rows there are (4), and how many columns (4).
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void RGB_color(int red_value, int green_value, int blue_value) {
    analogWrite(redPin, red_value);
    analogWrite(greenPin, green_value);
    analogWrite(bluePin, blue_value);
}

void playSuccess() {
    RGB_color(255, 0, 255);
    tone(buzzer, 400, 150);
    delay(150);
    tone(buzzer, 600, 150);
    delay(150);
    tone(buzzer, 800, 150);
    delay(150);
    noTone(buzzer);
}

void playError() {
    tone(buzzer, 147, 500);
    RGB_color(0, 255, 255);
    delay(50);
    noTone(buzzer);
}

void playInput() {
    tone(buzzer, 880, 250);
    RGB_color(255, 255, 0);
    delay(50);
    noTone(buzzer);
}

int unlockMode() {
    char customKey = customKeypad.getKey();
    Serial.println("Unlock Mode: Type Password to Continue");
    delay(500);

    for (int i = 0; i < PassLength; i++) {
        while (!(customKey = customKeypad.getKey())) {
            // wait infinitely for an input
        }
        if (password[i] != customKey) {
            Serial.println("WRONG PASSWORD");
            Serial.println(customKey);
            playError();
            return -1;
        }
        Serial.print("*");
    }

    Serial.print("");
    Serial.println("Device Successfully Unlocked!");
    playSuccess();
    return 0;
}

void setup() {
    Serial.begin(9600);  // Begin monitoring via the serial monitor
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    RGB_color(125, 125, 125);

    Serial.println("Press * to set a new password OR # to access the system");
}

void loop() {
    char customKey = customKeypad.getKey();
    if (customKey == '*') {  //if * pressed
        int access = unlockMode();
        if (access < 0) {
            Serial.println("Access denied. Cannot change password");
            RGB_color(125, 0, 0);

        } else {
            Serial.println("Welcome authoriazed user. Please enter a new password: ");
            delay(500);

            for (int i = 0; i < PassLength; i++) {
                while (!(customKey = customKeypad.getKey())) {
                    // wait infinitely for an input
                }
                password[i] = customKey;
                Serial.print("*");
                playInput();
            }
            Serial.println("");
            Serial.println("Password Successfully Changed!");
            playSuccess();
        }
    }
    if (customKey == '#') {
        int access = unlockMode();
        if (access < 0) {
            Serial.println("Acccess Denied.");
            //playError();

        } else {
            Serial.println("Welcome, authorized user. Go for it!");
            playSuccess();
        }
    }
}
