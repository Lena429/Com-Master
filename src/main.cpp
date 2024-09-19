#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x12        // slave address

void setup(){
    Wire.begin();

    Serial.begin(11520);
}

void loop(){

    Wire.beginTransmission(ADDRESS);
    Wire.write("Hello");
    Wire.endTransmission();

    delay(1000);
}