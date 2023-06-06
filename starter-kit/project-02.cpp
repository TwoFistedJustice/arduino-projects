int switchState = 0;
void setup() {
    pinMode(3, OUTPUT); // blue
    pinMode(4, OUTPUT); // green
    pinMode(5, OUTPUT); // yellow
    pinMode(2, INPUT);
}
void loop() {
    switchState = digitalRead(2);
    // comment
    if (switchState == LOW) {
        // button  pressed


        digitalWrite(3, LOW); // blue off
        digitalWrite(4,LOW ); // green off
        digitalWrite(5, HIGH); // yellow on
        delay(250); // wait 1/4 second
        // toggle LEDs
        digitalWrite(4, HIGH); // red on
        digitalWrite(5, LOW); // red off
        delay(250); // wait
    }
    else {  // button IS pressed

        digitalWrite(4, LOW); // green off
        digitalWrite(5, LOW); // yellow off
        // turn on both green and yellow
        delay(550);

        digitalWrite(3, HIGH); // blue on

    }
}