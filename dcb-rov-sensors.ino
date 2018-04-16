int light; // photoresistor
void setup()
{
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop()
{
light = analogRead(A0);
Serial.println(light);

}}
int redlight; // RPR
void setup()
{
pinMode(A1,INPUT);
Serial.begin(9600);
}

void loop()
{
redlight = analogRead(A1);
Serial.println(redlight);

}}
int greenlight; // GPR
void setup()
{
pinMode(A2,INPUT);
Serial.begin(9600);
}

void loop()
{
greenlight = analogRead(A2);
Serial.println(greenlight);

}}
int bluelight; //BPR
void setup()
{
pinMode(A3,INPUT);
Serial.begin(9600);
}

void loop()
{
bluelight = analogRead(A3);
Serial.println(bluelight);

}}
int pressure

MS5837 sensor; // pressure sensors 

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
