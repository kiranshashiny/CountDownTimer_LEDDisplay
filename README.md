# CountDownTimer_LEDDisplay
Arduino Project, Reads off the Analog pin, and starts counting backwards to zero.

This was a lazy afternoon project.

Works as a Count down timer backwards to zero.

Theory is to read the Analog data on A0, and map it from 0 - 100 seconds in increments of 5 seconds.

When the knob stops turning, the reading is taken and then starts counting backwards.

e.g: If the knob stops at 10 seconds - the counter starts counting backwards 10,9,8,....0...

Can be customized in code for 5 seconds, or 15 minutes or a few minute increments. 

The parts needed are 

	Arduino Uno,

	4.7k Potentiometer

	TM1637 7 segment LED display ( has 4 pins,  Vcc, GND, DIO and CLK )

Connections :

Potentiometer - Middle pin to A0 of Arduino, Wires on either ends of Pot to +5v and GND.

Seven segment LED : CLK and DIO to 13 and 12 of the Digital pins, Vcc and GND to +5v  and GND of Arduino.


The code is simple. It rounds to the nearest multiple of 5 seconds ( to a max of 100 seconds )

The formula was picked from the internet.

		x = ((n+4)/5)*5; // round up to nearest multiple of 5
 

The heart of the code is getting the formula from the mapped outputvalue:

Basis of the code is File-> Examples -> Analog-> AnalogInOutSerial which was later modified.

The "counter" global variable keeps track of the seconds that the potentiometer was stopped and starts counting backwards.

Other support programs used when developing were "File->Examples-> TM1637 -> TM1637Test"


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

