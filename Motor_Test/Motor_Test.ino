/*
This code was made so that you can test your Motors and check if they are running or not and have you connected them in the right way
If the motors are not running according to the manner that you have planned to, i.e. in an Inverted manner, just change the polarity of the connection of the Motor
Use an L298D Motor Driver for the Project and an Arduino UNO or MEGA for the Project
If you are using any other board, just make sure to change the motor pins accordingly so that it does not give you errors
*/

// We will first define the Motor Pins for both the motors

int m1p1 = 11;
int m1p2 = 10;

int m2p1 = 7;
int m2p2 = 6;

// Initializing the SETUP function

void setup() 
{
  // Defining the Motor Output Pins to output mode so that they can deliver output
  
  pinMode(m1p1, OUTPUT);    //Defining 1st Motor 1st Pin
  pinMode(m1p2, OUTPUT);    //Defining 1st Motor 2nd Pin
  pinMode(m2p1, OUTPUT);    //Defining 2nd Motor 1st Pin
  pinMode(m2p2, OUTPUT);    //Defining 2nd Motor 2nd Pin
}

// Initializing the LOOP function

void loop() 
{ 
  // Changing the Motor Output to High to check if the motors are running
  // Reverse the code content of LOW and HIGH to rotate the motors in the opposite direction
  // Make sure you have connected to motors in the correct order and direction to ensure smooth functioning and no do-overs
  
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
}
