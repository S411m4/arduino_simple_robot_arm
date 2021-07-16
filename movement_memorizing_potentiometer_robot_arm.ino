//basics idea
//there is different commands send, depending on it the robot will : start recording (R), stop recording (T), delete recorded moves (I), or show recorded moves (S)
//the robot will record moves in an array


//define signal pins in servo motors
#define servo1_pin 5
#define servo2_pin 6
#define servo3_pin 9

//define analog input pins for potenttiometer
#define pot1 A0
#define pot2 A1
#define pot3 A2

#include <Servo.h> //include servo library
#define array_size 100

int val1 = 0, val2 = 0, val3 = 0, degree1 = 0, degree2 =0, degree3 = 0; //variables to store potentiometers values
int record = 0;
char command; //store command
int servo1moves[array_size] = {}; //array to store movements
int servo2moves[array_size] = {};
int servo3moves[array_size] = {};
int move = 0; //to store current move

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
  
  	Serial.begin(9600); //to make it as indication to start memory mode
  
 
}


void loop()
{	
  //read potentiometer values
  val1 = analogRead(pot1);
  val2 = analogRead(pot2);
  val3 = analogRead(pot3);
  
  
  degree1 = map(val1, 0, 1023, 0, 180);
  degree2 = map(val2, 0, 1023, 0, 180);
  degree3 = map(val3, 0, 1023, 0, 180);
  
  servo1.write(degree1);
  servo2.write(degree2);
  servo3.write(degree3);
  
  command = Serial.read();
  
    
    if (record == 1)
    {
      
	servo1moves[move] = degree1;
      if(move < array_size)
      {move++;}
    
    servo2moves[move] = degree2;
      if(move < array_size)
      {move++;}
      
    servo3moves[move] = degree3;
      if(move < array_size)
      {move++;}
    }
  
  
  if (command == 'R')   //record moves
  {
    Serial.println(command);
  	record = 1;
  }
     else if(command == 'T') //stop recording
   {
    Serial.println(command);
	record = 0;
   }
  
  else if(command == 'I') //delete recorded moves
  {
    Serial.println(command);
	move = 0;
    memset(servo1moves, 0, sizeof(servo1moves));
    memset(servo2moves, 0, sizeof(servo2moves));
    memset(servo3moves, 0, sizeof(servo3moves));
  }
  
  
  else if(command == 'S') //show recorded moves
  {
    Serial.println(command);
	
    
	for(int j = 0; j<= move; j++)
    {
     
      	servo1.write(servo1moves[j]);
        servo2.write(servo2moves[j]);
        servo3.write(servo3moves[j]);
    }

  }
}
