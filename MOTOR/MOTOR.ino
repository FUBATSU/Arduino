#include <AFMotor.h>

AF_DCMotor rightmotor(2);
AF_DCMotor leftmotor(1);
int ss=255;

int sensorleft=A1;
int sensorcenter=A4;
int sensorright=A5;


int l1=1;
int l2=1;
int l3=1;

int f1=1;
int f2=1;
int f3=1;

//////////////////////////////////////

void setup()
{

 rightmotor.setSpeed(ss);
 rightmotor.run(FORWARD);  
 leftmotor.setSpeed(ss); 
 leftmotor.run(FORWARD);
 Serial.begin(9600);

 pinMode(sensorleft,INPUT);
 pinMode(sensorcenter,INPUT);
 pinMode(sensorright,INPUT);

}
///////////////////////////////////////////////////

void loop()
{
l1=digitalRead(sensorleft);
l2=digitalRead(sensorcenter);
l3=digitalRead(sensorright);
Serial.println(l1);
Serial.print(l2);
Serial.print(l3);



/////////////////////////////////////////////////////////////////////
if(l1==1&&l2==1&&l3==1)   //feedback when comes all sensor on white
{
l1=f1;
l2=f2;
l3=f3;
}

////////////////////////////////////////////////////////////////////////////
if(l1==1&&l2==0&&l3==0||l1==1&&l2==1&&l3==0)   //left turn
{
 rightmotor.setSpeed(ss);
 rightmotor.run(FORWARD);  
 leftmotor.setSpeed(00); 
 leftmotor.run(FORWARD);
 
}
else
if(l1==0&&l2==0&&l3==1||l1==0&&l2==1&&l3==1)  //right turn
{
 rightmotor.setSpeed(00);
 rightmotor.run(FORWARD);  
 leftmotor.setSpeed(ss); 
 leftmotor.run(FORWARD);
}
else
if(l1==0&&l2==1&&l3==0||l1==0&&l2==0&&l3==0)  //go forward straight
{
 rightmotor.setSpeed(ss);
 rightmotor.run(FORWARD);  
 leftmotor.setSpeed(ss); 
 leftmotor.run(FORWARD);;
}
else
if(l1==1&&l2==1&&l3==1) //stop
{
 rightmotor.setSpeed(00);
 rightmotor.run(BACKWARD);  
 leftmotor.setSpeed(00); 
 leftmotor.run(FORWARD);
}

///////////////////////////////////////////////////////////////////
f1=l1;
f2=l2;
f3=l3;        //memory variables
////////////////////////////////////////////////////////////////////
}
