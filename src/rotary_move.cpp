#include <Arduino.h>
#include "constants.h"

int movedClockwise() {
    return 1;
}

int movedCounterClockwise() {
    return -1;
}

int buttonPushed() {
    return 99;
}

int getRotaryMove(int rotaryALastMove) {

    int aState = digitalRead(ROTARY_A);
    int rotaryButtonPushed = digitalRead(ROTARY_PUSH);
    int rotationValue = 0;

    Serial.println(rotaryALastMove);
    Serial.println(aState);

    
    /* If the rotary button is pushed, we don't want 
    // to go any further
    // This reads backwards, so I'm guessing a button push 
    // returns 0. I don't understand.
    */
    if(!rotaryButtonPushed) {
        rotationValue = buttonPushed();
    }
    else {
        if (aState != rotaryALastMove){     
            // if outputB != outputA state, encoder is rotating clockwise
            if (digitalRead(ROTARY_B) != aState) { 
                rotationValue = movedClockwise();
            } 
            else {
                rotationValue = movedCounterClockwise();
            }
        }
    }

    Serial.println("returning value: ");
    Serial.println(rotationValue);
    return rotationValue;
} 

    
    
