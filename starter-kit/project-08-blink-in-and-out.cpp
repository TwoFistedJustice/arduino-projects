/*
* Project 8 from Arduino Starter Kit - MODIFIED
* Uses a tilt switch to control some LEDs
* You can also just stick a wire in the breadboard and pull it out
* when you want to reset the timer.
*  everything in parallel
* 6x LED + 6x R220
* 1x Tilt Swtich + 1 R10k
*  each LED is hooked up to a numbered pin on +
*  all grounded together with the switch
*
*  this version causes the lights to blink from the center
*  to the outer edge and back on repeat and solves the problem of the end leds lighting
 *  up longer than the middle ones.
* */

//arduino blinky lights
//        blink from middle to ends and back



#include <Arduino.h>
// switch control
const int switchPin = 8;
int switchState = 0;
int prevSwitchState = 0;

unsigned long previousTime = 0;

// These are your control constants.
// the number of leds between the middle and end of one side
const int ledsPerSide = 3;
// The two center leds. These are the first lights to activate
const int innerLedA = 4;
const int innerLedB = 5;
// milliseconds before firing off the next action
const long interval = 750;

// the outermost leds
const int outerLedA = innerLedA -  (ledsPerSide -1);
const int outerLedB = innerLedB + (ledsPerSide -1);

// leds will start one out of range then move into range on first run
// these are passed as arguments to the actions
int ledA = innerLedA + 1; // 4 3 2  - will start at 5
int ledB = innerLedB - 1; // 5 6 7  - will start at 4
boolean movingOutward = true;



// pass in current led values
void deactivate(int liteA, int liteB){
    digitalWrite(liteA, LOW);
    digitalWrite(liteB, LOW);
}

void  activate(int liteA, int liteB){
    digitalWrite(liteA, HIGH);
    digitalWrite(liteB, HIGH);
}

// increments/Decrements led numbers
void outward(){
    ledA -= 1;
    ledB += 1;
}

void inward(){
    ledA += 1;
    ledB -= 1;
}

void setup() {
    for ( int i = 2; i < 8; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}

void loop() {
    unsigned long currentTime = millis();
    if( currentTime - previousTime > interval) {
        previousTime = currentTime;
        // start by turning off the leds
        deactivate(ledA, ledB);

        // if the end leds are active, flip the boolean
        if (ledA == outerLedA){
            movingOutward = false;
        } else if ( ledA == innerLedA){
            movingOutward = true;
        }
        // in/decrement the led #s in the appropriate order according to the boolean
        if (movingOutward == true ){
            outward();
        } else {
            inward();
        }

        // turn on the selected leds
        activate(ledA, ledB);
    }
    switchState = digitalRead(switchPin);

// restarts the sequence if you flip the switch
    if (switchState != prevSwitchState){
        for (int i = 2; i < 8; i++ ){
            digitalWrite(i, LOW);
        }
    }
    prevSwitchState = switchState;
}