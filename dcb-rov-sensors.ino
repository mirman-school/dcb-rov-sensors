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
