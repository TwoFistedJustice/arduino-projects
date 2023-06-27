/* Project 8 from Arduino Starter Kit
 * Uses a tilt switch to control some LEDs
 *  everything in parallel
 * 6x LED + 6x R220
 * 1x Tilt Swtich + 1 R10k
 *  each LED is hooked up to a numbered pin on +
 *  all grounded together with the switch
 *
 *  This version causes the leds to blink sequentially from the middle toward the ends and then reverses
 * */

// BUG, the inner leds activate twice each go round
// It's lighting up 4,5 once going in and again going out causing it to stay on twice as long as the other lights.
#include <Arduino.h>
const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int innerLedA = 4;
int innerLedB = 5;

int outerLedA = 2;
int outerLedB = 7;

int ledA = innerLedA;
int ledB = innerLedB;

int previousLedA = 0; // used to turn off led before next led comes on
int previousLedB = 0; // used to turn off led before next led comes on

boolean outward = true;

long interval = 750;

/*
 *  BUG: the ends stays lit longer than the middle
 * */


void messaging(){
        Serial.print("Dark: ");
        Serial.print(previousLedA);
        Serial.print(", ");
        Serial.println(previousLedB);
        Serial.print("Lite: ");
        Serial.print(ledA);
        Serial.print(", ");
        Serial.println(ledB);
}

void resetOuters(){
//    Serial.println("Resetting outers");
    ledA = outerLedA;
    ledB = outerLedB;
}



void activateLeds(){
//        messaging();
        digitalWrite(previousLedA, LOW);
        digitalWrite(previousLedB, LOW);

        digitalWrite(ledA, HIGH);
        digitalWrite(ledB, HIGH);

        previousLedA = ledA;
        previousLedB = ledB;
}


void blinkOutward(){
    Serial.print("<-->: ");
    Serial.print(ledA);
    Serial.println(ledB);
    activateLeds();
    ledA--; // 3 2 | 1
    ledB++; // 6 7 | 8 (reset occurs)

    if( ledB > outerLedB ){
//        Serial.print(ledB);
//        Serial.println(" OUTERS");
        outward = false;
        resetOuters();
    }
}

void blinkInward(){
    Serial.print("-><-: ");
    Serial.print(ledA);
    Serial.println(ledB);
    ledA++; // 3 4
    ledB--; // 6 5
    activateLeds();
    if( ledB == innerLedB ){
//        Serial.println("INNERS");
        outward = true;
    }
}

void setup() {
    Serial.begin(9600);
    for( int x = 2; x < 8; x++ ){
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}
void loop() {
    unsigned long currentTime = millis(); // millis() is a counter that doesn't stop execution and doesn't reset?

    if( currentTime - previousTime > interval){  // if
        previousTime = currentTime;

        if (outward){
            blinkOutward();
        } else {
            blinkInward();
        }
    }
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
        for(int x = 2; x < 8; x++){
            digitalWrite(x, LOW);
        }
        ledA = innerLedA;
        ledB = innerLedB;
        previousTime = currentTime;
    }
    prevSwitchState = switchState;
}




