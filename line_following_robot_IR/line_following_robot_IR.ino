int mpin1=6;
int mpin2=7;
int mpin3=8;
int mpin4=9;
void setup() {
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(mpin1,OUTPUT);
  pinMode(mpin2,OUTPUT);
  pinMode(mpin3,OUTPUT);
  pinMode(mpin4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x=digitalRead(4);
  Serial.println(x);
  if(x==LOW){
    digitalWrite(5,HIGH);
    digitalWrite(mpin1,LOW);//stop if WHITE has found
    digitalWrite(mpin2,LOW);
    digitalWrite(mpin3,LOW);  
    digitalWrite(mpin4,LOW);
  }
 
  else{
    digitalWrite(5,LOW); 
    digitalWrite(mpin1,HIGH);
    digitalWrite(mpin2,LOW);
    digitalWrite(mpin3,HIGH);
    digitalWrite(mpin4,LOW);
}
}

// pictocode....

//void setup() {
//  //put your setup code here, to run once:
//  pinMode(2, INPUT);
//  pinMode(3, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(9, OUTPUT);
//  
//  
//}
//
//void loop() {
//  //put your main code here, to run repeatedly:
//  
//  
//  if(digitalRead(2)) {
//    analogWrite(3, 100);
//    analogWrite(5, 0);
//    analogWrite(6, 0);
//    analogWrite(9, 0);
//  }
//  else {
//    analogWrite(3, 0);
//    analogWrite(5, 0);
//    analogWrite(6, 100);
//    analogWrite(9, 0);
//  }
//}

    
