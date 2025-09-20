#define trigPin 9
#define echoPin 10
#define motorA1 2
#define motorA2 3
#define motorB1 4
#define motorB2 5

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);  // Send ultrasonic pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH); // Measure distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 20) {         //if no obstacle it goes FORWARD
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   
  } 
  else {
                               
  digitalWrite(motorA1, LOW);  //Stop when obstacle found
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(200);                  //change the delay accordingly 
  digitalWrite(motorA1, LOW);  //backward
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH); 
  delay(400);
  digitalWrite(motorA1, LOW);  //stop again
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(200);
  digitalWrite(motorA1, HIGH); //trun right
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  delay(400);
}
}

//TO CONTROL THE SPEED OF THE MOTOR CONVERT IT TO ANALOG PINS.

//#define trigPin 9
//#define echoPin 10
//#define motorA1 2
//#define motorA2 3
//#define motorB1 4
//#define motorB2 5
//
//long duration;
//int distance;
//
//void setup() {
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//  pinMode(motorA1, OUTPUT);
//  pinMode(motorA2, OUTPUT);
//  pinMode(motorB1, OUTPUT);
//  pinMode(motorB2, OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  
//  digitalWrite(trigPin, LOW);  // Send ultrasonic pulse
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  
//  
//  duration = pulseIn(echoPin, HIGH); // Measure distance
//  distance = duration * 0.034 / 2;
//
//  Serial.print("Distance: ");
//  Serial.println(distance);
//
//  if (distance > 20) {         //If no obstacle it goes FORWARD
//  analogWrite(motorA1, 100);
//  analogWrite(motorA2, 0);
//  analogWrite(motorB1, 100);
//  analogWrite(motorB2, 100);
//   
//  } 
//  else {
//                            
//  analogWrite(motorA1, 0);  //If obstacle found STOP 
//  analogWrite(motorA2, 0);
//  analogWrite(motorB1, 0);
//  analogWrite(motorB2, 0);
//  delay(200);                  //change the delay accordingly 
//  analogWrite(motorA1, 0);  //backward
//  analogWrite(motorA2, 100);
//  analogWrite(motorB1, 0);
//  analogWrite(motorB2, 100); 
//  delay(400);
//  analogWrite(motorA1, 0);  //stop again
//  analogWrite(motorA2, 0);
//  analogWrite(motorB1, 0);
//  analogWrite(motorB2, 0);
//  delay(200);
//  analogWrite(motorA1, 100); //trun right
//  analogWrite(motorA2, 0);
//  analogWrite(motorB1, 0);
//  analogWrite(motorB2, 100);
//  delay(400);
//}
//}
