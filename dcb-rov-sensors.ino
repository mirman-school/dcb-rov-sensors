// INCLUDES

// CONSTANTS
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
}

void loop()
{
 redVal = analogRead(redPin);
 Serial.print(redVal);
 Serial.print(",");
 greenVal = analogRead(greenPin);
 Serial.print(greenVal);
 Serial.print(",");
 blueVal = analogRead(bluePin);
 Serial.print(blueVal);
 Serial.print(",");
 rgbVal = analogRead(rgbPin);
 Serial.print(rgbVal);
 Serial.print(",");
 \"r"
}

#include <Wire.h>
#include "MS5837.h"

MS5837 sensor;

void setup() {
  
  Serial.begin(9600);
  
  Serial.println("Starting");
  
  Wire.begin();

  sensor.init();
  
  sensor.setFluidDensity(997); // kg/m^3 (997 freshwater, 1029 for seawater)
}

void loop() {

  sensor.read();

  Serial.print("Pressure: "); 
  Serial.print(sensor.pressure()); 
  Serial.println(" mbar");
  
  Serial.print("Temperature: "); 
  Serial.print(sensor.temperature()); 
  Serial.println(" deg C");
  
  Serial.print("Depth: "); 
  Serial.print(sensor.depth()); 
  Serial.println(" m");
  
  Serial.print("Altitude: "); 
  Serial.print(sensor.altitude()); 
  Serial.println(" m above mean sea level");

  delay(1000);
}
Python
This example uses the BlueRobotics MS5837 Python Library with the sensor connected to a Raspberry Pi. The Raspberry Pi uses 3.3V logic levels on the I2C pins, so a logic level shifter is not required.

import ms5837
import time

sensor = ms5837.MS5837_30BA() # Default I2C bus is 1 (Raspberry Pi 3)

# We must initialize the sensor before reading it
if not sensor.init():
        print "Sensor could not be initialized"
        exit(1)

# Print readings
while True:
        if sensor.read():
                print("P: %0.1f mbar  %0.3f psi\tT: %0.2f C  %0.2f F") % (
                sensor.pressure(), # Default is mbar (no arguments)
                sensor.pressure(ms5837.UNITS_psi), # Request psi
                sensor.temperature(), # Default is degrees C (no arguments)
                sensor.temperature(ms5837.UNITS_Farenheit)) # Request Farenheit
        else:
                print "Sensor read failed!"
                exit(1)
