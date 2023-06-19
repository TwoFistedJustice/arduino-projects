// Library must be installed via the IDE library manager under "sketch"
// I'm not sure what the capacitors are supposed to achieve in this project
// the mechanism appears to work exactly the same with or without them
// and even the read values do not change
// I also read the circuit V with my multi-meter and saw no difference in voltage
// drop between having them and not. Voltage dropped about 10% with every 180 swing.
#include <Servo.h>
Servo myServo;
int const potPin = A0;
int potVal;
int angle;
void setup(){
    myServo.attach(9);
    Serial.begin(9600);
}
void loop(){
    potVal = analogRead(potPin);
    Serial.print("potVal: ");
    Serial.print(potVal);
    //map: arg1 is the read value
    //     arg2 is the minimum expected read value
    //     arg3 is the maximum expected read value
    //     arg 4 is the minimum mapped value
    //     arg 4 is the maximum mapped value
    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);
    myServo.write(angle);
    // read 20 times per second
    delay(50);
}