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
