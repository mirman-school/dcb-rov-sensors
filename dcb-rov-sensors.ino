// INCLUDES
#include <Wire.h>
#include "MS5837.h"

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
 // the following are for pressure 
 Serial.println("Starting");
 Wire.begin();
 sensor.init();
 sensor.setFluidDensity(997); // kg/m^3 (997 freshwater, 1029 for seawater)
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

MS5837 sensor;


sensor = ms5837.MS5837_30BA() # Default I2C bus is 1 (Raspberry Pi 3)

if not sensor.init():
        print "Sensor could not be initialized"
        exit(1)

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
