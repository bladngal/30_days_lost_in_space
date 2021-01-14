// Code written by Alexander Eschenauer for the 30 Day Adventure Kit
// Learn more at https://inventr.io/adventure

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;

char password[PassLength] = {'0', '0', '0', '0'};

int buzzer = 10;

char buttons[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// byte rowPins[ROWS] = {5, 4, 3, 2};
// byte colPins[COLS] = {2, 3, 4, 5};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

int tones[ROWS][COLS] = {
    {31, 93, 147, 208},
    {247, 311, 370, 440},
    {523, 587, 698, 880},
    {1397, 2637, 3729, 4978}};

// Using the Keypad.h Library, we are going to define a custom keypad.
// In order to do that, it needs to know the following:
// What the keys are (a 2D Array of characters (char)),
// what pins are being used (2 thru 9),
// how many rows there are (4), and how many columns (4).
Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

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
            return -1;
        }
        Serial.print("*");
    }

    Serial.print("");
    Serial.println("Device Successfully Unlocked!");
    return 0;
}

void setup() {
    Serial.begin(9600);  // Begin monitoring via the serial monitor
    Serial.println("Press * to set a new password OR # to access the system");
}

void loop() {
    char customKey = customKeypad.getKey();
    if (customKey == '*') {  //if * pressed
        int access = unlockMode();
        if (access < 0) {
            Serial.println("Access denied. Cannot change password");
        } else {
            Serial.println("Welcome authoriazed user. Please enter a new password: ");
            delay(500);

            for (int i = 0; i < PassLength; i++) {
                while (!(customKey = customKeypad.getKey())) {
                    // wait infinitely for an input
                }
                password[i] = customKey;
                Serial.print("*");
            }
            Serial.println("");
            Serial.println("Password Successfully Changed!");
        }
    }
    if (customKey == '#') {
        int access = unlockMode();
        if (access < 0) {
            Serial.println("Acccess Denied.");
        } else {
            Serial.println("Welcome, authorized user. Go for it!");
        }
    }
}
