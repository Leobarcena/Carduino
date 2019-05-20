
int input='0'; //input to be used
#include <Servo.h>

Servo myservo1, myservo2, myservo3;
int headangle=60;
int neckangle=60;
int clawangle =90;



void setup() {
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  Serial.begin(9600); connection sane  baud rate as bluetooth
  
 }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void camforward()
{
  headangle=headangle+1;
  myservo2.write(headangle);
}

void cambackward()
{
  headangle=headangle-1;
  myservo2.write(headangle);
}

void camleft()
{
  neckangle=neckangle+1;
  myservo3.write(neckangle);
}

void camright()
{ 
  neckangle=neckangle-1;
  myservo3.write(neckangle);
}

void handOpen()
{
  clawangle=clawangle+1;
  myservo1.write(clawangle);
}

void handClose()
{
  clawangle=clawangle-5;
  myservo1.write(clawangle);
}
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
if(Serial.available()>0) //check if any data is being received, after sends to read
 {
  input = Serial.read(); //reads data resets the buffer to 0 and it is ready to read again
   Serial.println(input);
 }
 
// forward
if(input == '1')
  {
  digitalWrite(13,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(8,LOW);
   digitalWrite(10,HIGH);
   Serial.println(input);
   Serial.println("forward");
   }

 //back  
 else if(input == '2')
  {
   digitalWrite(13,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(10,LOW);
   Serial.println(input);
   Serial.println("back");
} 

//right
else if(input == '4')
  {
   digitalWrite(13,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(8,HIGH);
   digitalWrite(10,LOW);
   Serial.println(input);
   Serial.println("right");
   }

  //left 
 else if(input == '3')
  {
digitalWrite(13,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);
   digitalWrite(10,HIGH);
   Serial.println(input);
   Serial.println("left");
   }

   //default state
    else if(input == '0')
  {
   digitalWrite(13,LOW);
   digitalWrite(9,LOW);
   digitalWrite(8,LOW);
   digitalWrite(10,LOW);
   Serial.println("Idle");
   
  }

   else if(input == '5')
  {
    camforward();
    Serial.println("CamF");
  }

    else if(input == '6')
  {
    cambackward();
    Serial.println("CamB");
  }

    else if(input == '7')
  {
    camleft();
    Serial.println("CamL");
  }

    else if(input == '8')
  {
    camright();
    Serial.println("CamR");
  }

   else if(input == '9')
  {
    handOpen();
    Serial.println("clawOpen");
    Serial.println(input);
  }

   else if(input == 20)
  {
    handClose();
    Serial.println("clawClose");
    Serial.println(input);
  }
  
}




