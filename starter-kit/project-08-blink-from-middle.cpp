/* Project 8 from Arduino Starter Kit
 * Uses a tilt switch to control some LEDs
 *  everything in parallel
 * 6x LED + 6x R220
 * 1x Tilt Swtich + 1 R10k
 *  each LED is hooked up to a numbered pin on +
 *  all grounded together with the switch
 *
 *  This version causes the leds to blink sequentially from the middle toward the ends and then repeat
 * */

// BUG, the led number keeps incrementing, does not stop at 7
const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int initLedA = 4;
int initLedB = 5;

int ledA = initLedA;
int ledB = initLedB;

int previousLedA = 0; // used to turn off led before next led comes on
int previousLedB = 0; // used to turn off led before next led comes on

long interval = 750;
void setup() {
    for( int x = 2; x < 8; x++ ){
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}
void loop() {
    unsigned long currentTime = millis(); // millis() is a counter that doesn't stop execution and doesn't reset?

    if( currentTime - previousTime > interval){  // if
        previousTime = currentTime;

        digitalWrite(previousLedA, LOW);
        digitalWrite(previousLedB, LOW);

        digitalWrite(ledA, HIGH);
        digitalWrite(ledB, HIGH);

        previousLedA = ledA;
        previousLedB = ledB;

        ledA--;
        ledB++;

        if( ledB > 7 ){
            ledA = initLedA;
            ledB = initLedB;
        }
    }
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
        for(int x = 2; x < 8; x++){
            digitalWrite(x, LOW);
        }
        ledA = initLedA;
        ledB = initLedB;
        previousTime = currentTime;
    }
    prevSwitchState = switchState;
}
