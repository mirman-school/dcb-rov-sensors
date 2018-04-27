// WIRE MAPPINGS
// O: P/T Green
// Os: 
// G: DO
// Gs: P/T White
// Bl: Ground
// Bls: +5v
// Br: PR
// Brs: DO

// INCLUDES
#include <Wire.h>
#include "MS5837.h"
#include <SoftwareSerial.h>                          
#define rx 2                                    
#define tx 3   
int light; // photoresistor

MS5837 sensor;
SoftwareSerial myserial(rx, tx); 

// CONSTANTS
int lightPin = A3; 

// VARIABLES
int lightVal;
int pressure;


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
 lightVal = analogRead(lightPin);
 sensor.read();
 
 Serial.print(lightVal);
 Serial.print(",");
 Serial.print(",");
 Serial.print(",");
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
