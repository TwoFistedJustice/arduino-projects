const int sensorPin = A0;
// declare baseline to be set from setup()
float baselineTemp;
void setup() {
    // get the ambient temperature from the sensor, set the baseline temp
    int sensorVal = analogRead(sensorPin); // get the sensorvalue
    float voltage = (sensorVal/1024.0) * 5;
    baselineTemp = (voltage - .5) * 100; // convert v to C
    Serial.begin(9600); // open a serial port
    for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
    Serial.print("BASELINE TEMP:");
    Serial.println(baselineTemp, 1);
}



void loop() {
    int sensorVal = analogRead(sensorPin);
    float voltage = (sensorVal/1024.0) * 5;
    // Convert voltage to temp
    float temperature = (voltage - .5) * 100;
    float farhrenheit = (temperature * 1.8) + 32;
    Serial.print("Sensor value: ");
    Serial.print(sensorVal);
    Serial.print(", Volts: ");
    Serial.print(voltage);
    Serial.print(", degrees C: ");
    Serial.print(temperature, 1);
    Serial.print(",  F: ");
    Serial.println(farhrenheit, 1);
    if(temperature < baselineTemp + 2) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if(temperature >= baselineTemp + 3 && temperature < baselineTemp + 5) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if(temperature >= baselineTemp + 5 && temperature < baselineTemp + 7) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if( temperature >= baselineTemp + 7) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(3000);
}