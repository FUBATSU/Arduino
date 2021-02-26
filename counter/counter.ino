int trigPin1=4;
int trigPin2=10;
int echoPin1=3;
int echoPin2=9;
int distance1=0;
int distance2=0;
int cu,cd=0;//count up and count down 
void findDistance(void);
void findDistance(void){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

int  duration =pulseIn(echoPin1, HIGH, 5000);// here this pulsein function wont wait more then 5000us for the ultrasonic sound to came back. (due to this it wont measure more than 60cm)
                                           // it helps this project to use the gesture control in the defined space. 
                                           // so that, it will return zero if distance greater then 60m. ( it helps usually if we remove our hands infront of the sensors ).
 
int  r = 3.4 * duration / 2;                  // calculation to get the measurement in cm using the time returned by the pulsein function.     
  distance1 = r / 100.00;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  delay(100);
  }
void updown(int a,int b);
void updown(int a,int b){
  boolean k=1;
  boolean l=1;
  
  if(a<30 && b>30){
    k=1;
  }
  delay(80);
  if(a>30 && b<30){//checks after 80mili seconds whether he is entering and counting counter up the value
    k=1;
    if(l==k==1){
      cu+=1;
      l=0;
      k=0;
      }
    }
   if(a>30 && b<30){
    l=1;
  }
  delay(80);
  if(a<30 && b>30){//checks after 80mili seconds whether he is exiting and counting counter down the value
    l=1;
    if(l==k==1){
      cd+=1;
      l=0;
      k=0;
      }
    }
  else{
    k=l=0;
    }
    
  }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  findDistance();
 int a=distance1;
 int b=distance2;
  updown(a,b);
 int d=cu;
 int e=cd;
  Serial.println(d-e);
}
