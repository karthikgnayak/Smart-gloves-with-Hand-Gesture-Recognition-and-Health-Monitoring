int M1=2;
int M2=3;
int M3=4;
int M4=5;
int M5=6;
int M6=7;

char ch;

void setup() {
  // put your setup code here, to run once:
pinMode(M1,OUTPUT);
pinMode(M2,OUTPUT);
pinMode(M3,OUTPUT);

pinMode(M4,OUTPUT);
pinMode(M5,OUTPUT);
pinMode(M6,OUTPUT);

digitalWrite(M1,LOW);
digitalWrite(M2,LOW);
digitalWrite(M3,LOW);
digitalWrite(M4,LOW);
digitalWrite(M5,LOW);
digitalWrite(M6,LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()>0)
{
  ch=Serial.read();
 Serial.print(ch);
  delay(200);
 if(ch=='A'){
  digitalWrite(M1,HIGH);
  delay(200);
  digitalWrite(M1,LOW);
  delay(200);
 }
 if(ch=='B'){
  digitalWrite(M2,HIGH);
  delay(200);
  digitalWrite(M2,LOW);
  delay(200);
 }

 if(ch=='C'){
  digitalWrite(M3,HIGH);
  delay(200);
  digitalWrite(M3,LOW);
  delay(200);
 }

 if(ch=='D'){
  digitalWrite(M4,HIGH);
  delay(200);
  digitalWrite(M4,LOW);
  delay(200);
 }
 
  if(ch=='E'){
  digitalWrite(M5,HIGH);
  delay(200);
  digitalWrite(M5,LOW);
  delay(200);
 }
  if(ch=='F'){
  digitalWrite(M6,HIGH);
  delay(200);
  digitalWrite(M6,LOW);
  delay(200);
 }
 }
}
