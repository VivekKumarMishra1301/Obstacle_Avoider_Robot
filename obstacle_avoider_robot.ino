
#include<Servo.h>

int i=0,j=0,t=A0,e=7,ch,lmr=11,rmr=9,rd,ld;
Servo visa;
void servor();
void servol();
void movef();
void moveb();
void stop();
void turnr();
void turnl();
int us();
void setup() 
{
  
  
   visa.attach(8);
   pinMode(t,OUTPUT);
   pinMode(e,INPUT);
   pinMode(rmr,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(lmr,OUTPUT);
   pinMode(12,OUTPUT);
  
}

void loop() 
{ 
  movef();
ch=us();
if(ch<=20){
  stop();
  delay(1000);
  moveb();
  delay(500);
  stop();
  servor();
  rd=us();
  delay(1000);
  visa.write(90);
  delay(1000);
  servol();
  ld=us();
  delay(1000);
  visa.write(90);
  if(rd>=ld){
    turnr();
    delay(1000);
    stop();
    delay(500);
    movef();
  }else{
    turnl();
    delay(1000);
    stop();
    delay(500);
    movef();
    
  }
}else{
  movef();
}

 
}
 void servol(){
for(int i=90;i<=180;i++){
    visa.write(i);
    delay(5);
  }
  
}
void servor(){
  for(int i=90;i>=0;i--){
    visa.write(i);
    delay(5);
  }
  
}
 int us()
{
  int dura;
  int dist,rd,ld;
    digitalWrite(t,LOW);
  delay(10);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);

  dura = pulseIn(e,HIGH);
  dist=dura/58;
  
  return(dist);
}
void turnr(){
  digitalWrite(rmr,LOW);
   digitalWrite(10,LOW);
    digitalWrite(lmr,LOW);
     digitalWrite(12,HIGH);
}
void turnl(){
  digitalWrite(rmr,HIGH);
   digitalWrite(10,LOW);
    digitalWrite(lmr,LOW);
     digitalWrite(12,LOW);
}
void movef(){
  digitalWrite(rmr,HIGH);
   digitalWrite(10,LOW);
    digitalWrite(lmr,LOW);
     digitalWrite(12,HIGH);
}
void moveb(){
  digitalWrite(rmr,LOW);
   digitalWrite(10,HIGH);
    digitalWrite(lmr,HIGH);
     digitalWrite(12,LOW);
}
void stop(){
  digitalWrite(rmr,LOW);
   digitalWrite(10,LOW);
    digitalWrite(lmr,LOW);
     digitalWrite(12,LOW);
}
