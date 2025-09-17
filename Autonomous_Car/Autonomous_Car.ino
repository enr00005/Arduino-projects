#include <Servo.h>
Servo eby;
#define trigPin 6
#define echoPin 7
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
//int n; 
int duration,  distance;
//String readString;

//#include <Servo.h> 
//Servo myservo1;  // create servo object to control servo 
//Servo myservo2;

void setup()  {
  Serial.begin(9600);
  eby.attach(8);
  eby.write(0);
//  myservo1.attach(8); // assigns the servo to a pin
//  myservo2.attach(9);
  pinMode(trigPin, OUTPUT); //assign ultrasonic
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(motor1pin1, OUTPUT); // assign motor
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  _delay_ms(500);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,  HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
     
  if (distance < 40)  { // this is the distance which the rover has to stop
      digitalWrite(13, HIGH);
      eby.write(90);
      delay(1000);
      digitalWrite(motor1pin1, HIGH);  //move right 
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      delay(3000);
//    myservo1.write(n); // controls the direction of the motors
//    myservo2.write(180-n);

//delay(1000);  // how long the wheels spin
//   myservo1.write(n);
//   myservo2.write(90-n);
//delay(500);
}
  else {                             // if there is no obstacle move forward
    digitalWrite(13, LOW);
    eby.write(0);
    delay(1000);
    digitalWrite(motor1pin1, HIGH);  //move forward
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);  
//    myservo1.write(180-n);
//    myservo2.write(n);
}
}  
