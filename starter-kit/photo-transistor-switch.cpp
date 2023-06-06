/*
 *  Uses a photo transistor with a 10k resistor hooked up to A1 in \\ with ground
 *  to control a single LED with a 220 resistor hooked up to pin 9 as ground
 *  The loop runs 20 times per second
 *  It only updates the serial monitor if the light level changes by more than "1"
 *
 * */

const int ledPin = 9;
const int sensorPin = A1;
int sensorValue =  0;
int oldValue = -1;  // used to compare current input to previous input
int adjustedValue = 0; // will be sensor input divided by four
int testValue = 40; // change this to control at which light level the led is activated


void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    delay(50);
    sensorValue = analogRead(sensorPin);
    adjustedValue = sensorValue / 5;
    if (adjustedValue > (oldValue + 1 )|| adjustedValue < (oldValue - 1 ) ){
        Serial.print("Adjusted Sensor Values \t: ");
        Serial.println(adjustedValue);
        if (adjustedValue > testValue){
            analogWrite(ledPin, 1);
        } else {
            analogWrite(ledPin, -1);
        }
        oldValue = adjustedValue;
    }
}