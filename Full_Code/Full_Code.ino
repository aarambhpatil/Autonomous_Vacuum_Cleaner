/*
This is the cumulative code made for the final working model of the Vacuum Cleaner
This is basic code for any Arduino UNO or MEGA board
The motor driver used is an L298 with 2*5V DC Motors
Ultrasonic Sensors used are HC-SR04
The Vacuum we made was made using a 5V DC Motor in a Pipe such that it creates a suction
For the dust collection, we used a Bag Attached to the back of the Pipe
*/

// Define the Motor Pins for Motor 1 and 2
#define m1p1 10
#define m1p2 11

#define m2p1 6
#define m2p2 7

// Define the IR Pin that is connected in the front below the Chassis to detect Ground at all times
#define irpin 5

// Define the Ultrasonic Sensor Pins for the detection of Walls around the robot
#define trig1 9
#define echo1 8

#define trig2 13
#define echo2 12

#define trig3 3
#define echo3 2

//Define the Vacuum Pin which is connected to another switch, so that it can be turned on whenever required
#define vaccuum 4

int distance1, distance2, distance3;
long duration;

void setup()
{
  Serial.begin(9600);
  pinMode(vaccuum, OUTPUT);       //Defining Vaccuum Pin
  pinMode(irpin, INPUT);          //Defining IR Module at Pin
  pinMode(trig1, OUTPUT);         //Defining 1st Trig Pin at
  pinMode(trig2, OUTPUT);         //Defining 2nd Trig Pin at
  pinMode(trig3, OUTPUT);         //Defining 3rd Trig Pin at
  pinMode(echo1, INPUT);          //Defining 1st Echo Pin at
  pinMode(echo2, INPUT);          //Defining 2nd Echo Pin at
  pinMode(echo3, INPUT);          //Defining 3rd Echo Pin at
  pinMode(m1p1, OUTPUT);          //Defining 1st Motor 1st Pin
  pinMode(m1p2, OUTPUT);          //Defining 1st Motor 2nd Pin
  pinMode(m2p1, OUTPUT);           //Defining 2nd Motor 1st Pin
  pinMode(m2p2, OUTPUT);          //Defining 2nd Motor 2nd Pin
  digitalWrite(vaccuum, HIGH);    //Turning on the Motor
}

void ultrasonic1()    //Calculating Ultrasonic 1
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration = pulseIn(echo1, HIGH);
  distance1 = duration * 0.034 / 2;
}

void ultrasonic2()    //Calculating Ultrasonic 2
{
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration = pulseIn(echo2, HIGH);
  distance2 = duration * 0.034 / 2;
}

void ultrasonic3()    //Calculating Ultrasonic 3
{
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  duration = pulseIn(echo3, HIGH);
  distance3 = duration * 0.034 / 2;
}

void directionn()
{
  ultrasonic1();
  ultrasonic2();
  ultrasonic3();
}

void stopp(int a)
{
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, LOW);
  delay(a);
}

void rotateright()
{
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(100);
}


void rotateleft()
{
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(100);
}

void forwardmove()
{
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  delay(100);
}

void reversemove()
{
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  delay(100);
}

void staircase()
{
  int ir_status = digitalRead(irpin);

  if (ir_status == 1)
  {
    stopp(1);
    rotateright();
  }  
}

void loop()
{
  
  directionn();

  Serial.print("D1 = ");
  Serial.println(distance1);

  Serial.print("D2 = ");
  Serial.println(distance2);

  Serial.print("D3 = ");
  Serial.println(distance3);

  if (distance1 < 50)
  {
    stopp(1);
    reversemove();
    
    if (distance3 < 50)
    {
      rotateleft();
    }

    if (distance2 < 50)
    {
      rotateright();
    }
  }
  
  else
  {
    forwardmove();
  }
} 
