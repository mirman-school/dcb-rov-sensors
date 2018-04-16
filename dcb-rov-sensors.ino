int light; // photoresistor

void setup()
{
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop()
{
  light = analogRead(A1);
  Serial.println(light);
}






#include "MS5837.h"

MS5837 sensor; // pressure sensors

int PTDA

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
  Serial.print(sensor.pressure(A0)); 
  Serial.println(" mbar");
  
  Serial.print("Temperature: "); 
  Serial.print(sensor.temperature(A4)); 
  Serial.println(" deg C");
  
  Serial.print("Depth: "); 
  Serial.print(sensor.depth(A5)); 
  Serial.println(" m");
  
  Serial.print("Altitude: "); 
  Serial.print(sensor.altitude(A6)); 
  Serial.println(" m above mean sea level");

  delay(1000);
}
