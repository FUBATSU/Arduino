int trigPin1=4;
int echoPin1=3;
int distance1=0;
int cu=0,cd=0;//count up and count down 
void findDistance(void);
void findDistance (void)                   
{ 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

int duration =pulseIn(echoPin1, HIGH, 5000);// here this pulsein function wont wait more then 5000us for the ultrasonic sound to came back. (due to this it wont measure more than 60cm)
                                           // it helps this project to use the gesture control in the defined space. 
                                           // so that, it will return zero if distance greater then 60m. ( it helps usually if we remove our hands infront of the sensors ).
 
int r = 3.4 * duration / 2;                  // calculation to get the measurement in cm using the time returned by the pulsein function.     
  distance1 = r / 100.00;}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  findDistance();
  int a=distance1;
  delay(400);
  findDistance();
  int b=distance1;
  int cu,cd=0;
  if(a>b){
  cu+=1;
  }
 else if(a<b){
  cd+=1;
  }
 Serial.println(cd);
 
}
