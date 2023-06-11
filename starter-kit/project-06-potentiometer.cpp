*
* potentiometer with 10k R on - side, other side to +, middle pin to A0
* piezo hooked up to ground and pin 11
* pitch max value was lowered to 2000 because 4000 was piercing
* */


int potVal;
int const potPin = A0;
int potLow = 1023;
int potHigh = 0;
int ledPin = 13;
void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

}
void loop() {
    potVal = analogRead(potPin);
    int pitch = map(potVal, potLow, potHigh, 50, 2000);
    Serial.print("potVal: ");
    Serial.print(potVal);
    Serial.print(" pitch: ");
    Serial.println(pitch);
    tone(11, pitch, 20);
    delay(50);
}