#include <AFMotor.h>
#include <Wire.h>
#include "MS5837.h"

MS5837 bar;

#include <SoftwareSerial.h>                           //we have to include the SoftwareSerial library, or else we can't use it
#define rx 2                                          //define what pin rx is going to be
#define tx 3                                          //define what pin tx is going to be


SoftwareSerial myserial(rx, tx);                      //define how the soft serial port is going to work

String inputstring = "";                              //a string to hold incoming data from the PC
String sensorstring = "";                             //a string to hold the data from the Atlas Scientific product
boolean input_string_complete = false;                //have we received all the data from the PC
boolean sensor_string_complete = false;               //have we received all the data from the Atlas Scientific product
float DO;                                             //used to hold a floating point number that is the DO


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);                               //set baud rate for the software serial port to 9600
  inputstring.reserve(10);                            //set aside some bytes for receiving data from the PC
  sensorstring.reserve(30);        
  Wire.begin();
  
  bar.init();
  bar.setFluidDensity(122); // kg/m^3 (997 freshwater, 1029 for seawater)
  Serial.println("pressure,temperature,depth,altitude,light,dissolvedoxygen");
}void serialEvent() {                                  //if the hardware serial port_0 receives a char
  inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
  input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC 
}

void loop() {

  if (input_string_complete && millis() % 1000 < 100){                         //if a string from the PC has been received in its entirety
                   //reset the flag used to tell if we have received a completed string from the PC

    bar.read();
    Serial.print(bar.pressure()); 
    Serial.print(",");
    Serial.print(bar.temperature()); 
    Serial.print(",");
    Serial.print(bar.depth()); 
    Serial.print(",");
    Serial.print(bar.altitude()); 
    Serial.print(",");
    Serial.println(analogRead(A1));
    Serial.print(",");
    myserial.print(inputstring);                      //send that string to the Atlas Scientific product
    myserial.print('\r');                             //add a <CR> to the end of the string 
    inputstring = "";                                 //clear the string
    input_string_complete = false;     
  }

  if (myserial.available() > 0) {                     //if we see that the Atlas Scientific product has sent a character
    char inchar = (char)myserial.read();              //get the char we just received
    sensorstring += inchar;                           //add the char to the var called sensorstring
    if (inchar == '\r') {                             //if the incoming character is a <CR>
      sensor_string_complete = true;                  //set the flag
    }
  }

  if (sensor_string_complete) {                       //if a string from the Atlas Scientific product has been received in its entirety                 //send that string to the PC's serial monitor
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

}
