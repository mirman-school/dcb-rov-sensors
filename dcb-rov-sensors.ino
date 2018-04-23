// INCLUDES
#include <Wire.h>
#include "MS5837.h"

// CONSTANTS
MS5837 sensor;
int redPin = A0; // photoresistor
int greenPin = A1; // RPR
int bluePin = A2;
int rgbPin = A3; 

// VARIABLES
int redVal;
int greenVal;
int blueVal;
int rgbVal;
int pressure


void setup()
{
 pinMode(redPin,INPUT);
 pinMode(bluePin,INPUT);
 pinMode(greenPin,INPUT);
 pinMode(redPin,INPUT);
 Serial.begin(9600);
 // the following are for pressure 
 Serial.println("Starting");
 Wire.begin();
 sensor.init();
 sensor.setFluidDensity(997); // kg/m^3 (997 freshwater, 1029 for seawater)
}

void loop()
{
 redVal = analogRead(redPin);
 greenVal = analogRead(greenPin);
 blueVal = analogRead(bluePin);
 rgbVal = analogRead(rgbPin);
 sensor.read();
 
 Serial.print(rgbVal);
 Serial.print(",");
 Serial.print(redVal);
 Serial.print(",");
 Serial.print(greenVal);
 Serial.print(",");
 Serial.print(blueVal);
 Serial.print(",");
 Serial.print(sensor.pressure()); 
 Serial.print(",");
 Serial.print(sensor.temperature());
 Serial.print(",");
 Serial.print(sensor.depth()); 
 Serial.print(",");
 Serial.print(sensor.altitude()); 
 Serial.print(",");
 Serial.print("\r");
 delay(1000);
}
