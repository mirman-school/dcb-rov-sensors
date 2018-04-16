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
int greenlight; // GPR
int bluelight; //BPR
int PTDA

MS5837 sensor; // pressure sensors 

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
