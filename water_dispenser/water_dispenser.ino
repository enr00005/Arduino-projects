#include <Servo.h>
Servo water;
long times;
int distance;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  // pinMode(5,OUTPUT); //buzzer
  water.attach(6);
  water.write(0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2,LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);

  digitalWrite(2,LOW);
  times=pulseIn(3,HIGH);
  distance=times*0.034/2;
  Serial.println(distance);
  if(distance<50){
    digitalWrite(5,HIGH);
    water.write(90);
  }
  else{
    digitalWrite(5,LOW);
    water.write(0);
    delay(1000);
  }
}
