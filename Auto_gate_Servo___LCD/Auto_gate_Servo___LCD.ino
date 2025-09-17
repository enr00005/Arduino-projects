#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo eby;
long times;
int distance;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT); //buzzer
  eby.attach(6);
  eby.write(0);
  lcd.init();
  lcd.backlight();
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
  lcd.clear();
  if(distance<50){
    digitalWrite(5,HIGH);
    eby.write(90);
    lcd.setCursor(0,0);
    lcd.print("GATE OPEN");
    lcd.setCursor(9,0);
    lcd.print(distance);
  }
  else{
    digitalWrite(5,LOW);
    eby.write(0);
    lcd.setCursor(0,0);
    lcd.print("GATE CLOSE");
    lcd.setCursor(11,1);
    lcd.print(distance);
  }
}
