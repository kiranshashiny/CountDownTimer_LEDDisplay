/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/
#include <TM1637Display.h>

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

// Module connection pins (Digital Pins)
#define CLK 13
#define DIO 12

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   500
TM1637Display display(CLK, DIO);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  display.setBrightness(0x0f);
  display.showNumberDec(0, false); 


}
int oldpot =0;
int counter=0;

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 100);

 
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  int x = ((outputValue+4)/5)*5;
  
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\t x = ");
  Serial.print (x);
  
  if ( oldpot == x ) {
    if ( x >4 ){
       counter--;
       if ( counter == 0) {  Serial.print ("BEEP BEEP"); }
       Serial.print ("  Counter = ");
       Serial.print ( counter);
       
       display.showNumberDec(counter, false); 
    }
  } else {
    oldpot  = x;
    counter = x;
    display.showNumberDec(counter, false); 

  }
  Serial.println ();
  delay(1000);
}
