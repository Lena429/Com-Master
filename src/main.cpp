#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x12        // slave address
short mesLen;

void setup(){
    Wire.begin(21, 22);

    Serial.begin(115200);
}

void loop(){
    char message[] = "Hello Kaden\0";

    Wire.beginTransmission(ADDRESS);
    // send the data
    Wire.write(message);
    Wire.endTransmission();

    Serial.println("Data Sent");

    delay(500);

    Wire.requestFrom(ADDRESS, strlen(message));


    char retMes[mesLen];

    int index = 0;
    if (Wire.available()){
        while(Wire.available()){
        retMes[index] = Wire.read();
        index++;
        }
        retMes[index] = '\0';

        Serial.println("Data Received");
        Serial.println(retMes);
    }

    delay(1000);
}