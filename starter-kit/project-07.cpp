/* Project 7 from Arduino Starter Kit
 * builds a resistor ladder with buttons R[220, 10k, 1m, 10k]
 * piezo on pin 8
 * */

//int notes[] = {262, 294, 330, 349};
// refactor to note names
int noteC = 262;
int noteD = 294;
int noteE = 330;
int noteF = 349;



void setup(){
    Serial.begin(9600);
}
void loop(){
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    if(keyVal == 1023){
        // play C
        tone(8,noteC);
    }
    else if(keyVal >= 990 && keyVal <= 1010){
        // play D
        tone(8, noteD);
    }
    else if(keyVal >= 505 && keyVal <= 515){
        // play E
        tone(8, noteE);
    }
    else if(keyVal >= 5 && keyVal <= 50){
        // play F
        tone(8, noteF);
    }
    else {
        noTone(8);
    }
}

