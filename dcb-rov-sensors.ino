#include "MS5837.h"
#include <SoftwareSerial.h>                          
#define rx 2(A2)                                     
#define tx 3(A3)    
int light; // photoresistor
int redlight; // RPR
int greenlight; // GPR
int bluelight; //BPR

MS5837 sensor; // pressure sensors

void setup()
{
  pinMode(A1,INPUT);
  Serial.begin(9600);                             
  Serial.begin(9600);                                 //set baud rate for the hardware serial port_0 to 9600
  myserial.begin(9600);                               //set baud rate for the software serial port to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);                           //set aside some bytes for receiving data from Atlas Scientific product
  void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC 
  Serial.begin(9600);
  
  Serial.println("Starting");
  
  Wire.begin();

  sensor.init();
  
  sensor.setFluidDensity(997); // kg/m^3 (997 freshwater, 1029 for seawater)
}

void loop() {                                        
{
  light = analogRead(A1);
  Serial.println(light);
  
   light = analogRead(A7);
  Serial.println(light);
  
   light = analogRead(A);
  Serial.println(light);
  
   light = analogRead(A1);
  Serial.println(light);
}
              

  Serial.print("Pressure: "); 
  Serial.print(sensor.pressure(A0)); 
  Serial.println(" mbar");
  
  Serial.print("Temperature: "); 
  Serial.print(sensor.temperature(A0)); 
  Serial.println(" deg C");
  
  Serial.print("Depth: "); 
  Serial.print(sensor.depth(A0)); 
  Serial.println(" m");
  
  Serial.print("Altitude: "); 
  Serial.print(sensor.altitude(A0)); 
  Serial.println(" m above mean sea level");

  delay(1000);
  }
}
