#include <AFMotor.h>

AF_DCMotor rightmotor(2);
AF_DCMotor leftmotor(1);
int ss=200;
void setup() {
  // put your setup code here, to run once:
rightmotor.setSpeed(ss);
 rightmotor.run(FORWARD);  
 leftmotor.setSpeed(ss); 
 leftmotor.run(FORWARD);
}

void loop() {
  // put your main code here, to run repeatedly:

}
