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

String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_complete = false;               //have we received all the data from the Atlas Scientific product
float DO;                                             //used to hold a floating point number that is the DO

// CONSTANTS
int lightPin = A3; 

// VARIABLES
int lightVal;

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

  if (input_string_complete){                         //if a string from the PC has been received in its entirety
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    myserial.print('\r');                             //add a <CR> to the end of the string 
    inputstring = "";                                 //clear the string
    input_string_complete = false;                    //reset the flag used to tell if we have received a completed string from the PC
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;                           //add the char to the var called sensorstring
    if (inchar == '\r') {                             //if the incoming character is a <CR>
      sensor_string_complete = true;                  //set the flag
    }
  }


  if (sensor_string_complete== true) {                //if a string from the Atlas Scientific product has been received in its entirety
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
    /*                                                //uncomment this section to see how to convert the DO reading from a string to a float 
    if (isdigit(sensorstring[0])) {                   //if the first character in the string is a digit
      DO = sensorstring.toFloat();                    //convert the string to a floating point number so it can be evaluated by the Arduino
      if (DO >= 6.0) {                                //if the DO is greater than or equal to 6.0
        Serial.println("high");                       //print "high" this is demonstrating that the Arduino is evaluating the DO as a number and not as a string
      }
      if (DO <= 5.99) {                               //if the DO is less than or equal to 5.99
        Serial.println("low");                        //print "low" this is demonstrating that the Arduino is evaluating the DO as a number and not as a string
      }
    }
    */
    sensorstring = "";                                //clear the string
    sensor_string_complete = false;                   //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
  }

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

void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC 
}
