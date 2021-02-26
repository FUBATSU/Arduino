void setup() {
  // put your setup code here, to run once:
  pinMode(D0,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,INPUT);
  Serial.begin(9600);
}

void loop() {
  int t=0;
  int d=0;
  digitalWrite(D2,HIGH);
  delayMicroseconds(10);
  digitalWrite(D2,LOW);
  t=pulseIn(D3,HIGH);
  d=0.034*t/2;
  Serial.println(d);
 if(d<=10) {
  digitalWrite(D0,HIGH);
  digitalWrite(D4,LOW);
 }
else if(d<=20 && d>10) {
  digitalWrite(D0,LOW);
  digitalWrite(D4,HIGH);
 }
else if(d<=30 && d>20) {
  digitalWrite(D0,LOW);
  digitalWrite(D4,LOW);
  
 }
 else if(d>30) {
  digitalWrite(D0,HIGH);
  digitalWrite(D4,HIGH);

 }
 
}
