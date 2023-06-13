/* Refactor of project 7 to use the Tone library
 * */
#include <Tone.h>
Tone tone1;

void setup(){
    Serial.begin(9600);
    tone1.begin(8);
}
void loop(){
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    if(keyVal == 1023){
        // play C
        tone1.play(NOTE_C4);
    }
    else if(keyVal >= 990 && keyVal <= 1010){
        // play D
        tone1.play(NOTE_D4);
    }
    else if(keyVal >= 505 && keyVal <= 515){
        // play E
        tone1.play(NOTE_E4);
    }
    else if(keyVal >= 5 && keyVal <= 50){
        // play F
        tone1.play(NOTE_F4);
    }
    else {
        tone1.stop();
        Serial.println("No TONE");
    }
}