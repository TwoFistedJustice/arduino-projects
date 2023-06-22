/* Project 8 from Arduino Starter Kit
 * Uses a tilt switch to control some LEDs
 *  everything in parallel
 * 6x LED + 6x R220
 * 1x Tilt Swtich + 1 R10k
 *  each LED is hooked up to a numbered pin on +
 *  all grounded together with the switch
 * */

// BUG, the led number keeps incrementing, does not stop at 7
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
// set interval to 1 sec because 10 minutes per the book is wayyyy too long
long interval = 1000;
void setup() {
    Serial.begin(9600);
    for( int x = 2; x < 8; x++ ){
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}
void loop() {
    unsigned long currentTime = millis(); // millis() is a counter that doesn't stop execution and doesn't reset?
    Serial.print("currentTime: ");
    Serial.print(currentTime);
    Serial.print(" ");
    Serial.print("variable $led: ");
    Serial.println(led);
    if( currentTime - previousTime > interval){  // if
        previousTime = currentTime;
//        digitalWrite(led - 1, LOW);
        digitalWrite(led, HIGH);
        led++;
        if( led == 7 ){
            Serial.println("RESET LED");

        }
    }
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
        for(int x = 2; x < 8; x++){
            digitalWrite(x, LOW);
        }
        led = 2;
        previousTime = currentTime;
    }
    prevSwitchState = switchState;
}