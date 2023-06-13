/* Project 7 from Arduino Starter Kit
 * builds a resistor ladder with buttons R[220, 10k, 1m, 10k]
 * piezo on pin 8
 * */

// set up array w 6 buttons
//int buttons[6];
//int buttons[0] = 2; // book has int type, IDE complains abou redeclaration
int notes[] = {262, 294, 330, 349};
void setup(){
    Serial.begin(9600);
}
void loop(){
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    if(keyVal == 1023){
        // play C
        tone(8,notes[0]);
    }
    else if(keyVal >= 990 && keyVal <= 1010){
        // play D
        tone(8, notes[1]);
    }
    else if(keyVal >= 505 && keyVal <= 515){
        // play E
        tone(8, notes[2]);
    }
    else if(keyVal >= 5 && keyVal <= 50){
        // play F
        tone(8, notes[3]);
    }
    else {
        noTone(8);
    }
}

