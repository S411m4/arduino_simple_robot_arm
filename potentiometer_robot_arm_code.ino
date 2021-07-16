//define signal pins in servo motors
#define servo1_pin 5
#define servo2_pin 6
#define servo3_pin 9

//define analog input pins for potenttiometer
#define pot1 A0
#define pot2 A1
#define pot3 A2

#include <Servo.h> //include servo library

int val1 = 0, val2 = 0, val3 = 0; //variables to store potentiometers values

 //intialize servo motors
	Servo servo1;
  	Servo servo2;
  	Servo servo3;


void setup()
{
	//attach servo motors to their pins  	
  	servo1.attach(servo1_pin);
  	servo2.attach(servo2_pin);
  	servo3.attach(servo3_pin);
}


void loop()
{	
  //read potentiometer values
  val1 = analogRead(pot1);
  val2 = analogRead(pot2);
  val3 = analogRead(pot3);
  
  //map values to servo degrees
  val1 = map(val1, 0, 1023, 0, 180);
  val2 = map(val2, 0, 1023, 0, 180);
  val3 = map(val3, 0, 1023, 0, 180);
  
  //write degrees to servo motor
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
 
  delay(15);

  
}
