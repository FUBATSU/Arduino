void setup() {
  // put your setup code here, to run once:
  pinMode(D4,OUTPUT);
  pinMode(D0,OUTPUT);
  
}
  int i=200;
void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(D4,HIGH);
  digitalWrite(D0,LOW);
  delay(i);
  digitalWrite(D4,LOW);
  digitalWrite(D0,HIGH);
  delay(i);
  i-=1;
  if(i==0){
  digitalWrite(D4,LOW);
  digitalWrite(D0,LOW);
  delay(3000);
    }
  
  
  
}
