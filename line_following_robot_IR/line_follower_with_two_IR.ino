void setup() {
  //put your setup code here, to run once:
  pinMode(2, INPUT);    //senosr 1
  pinMode(4, INPUT);    //sensor 2
  
  //[The analog pins are used because we could control the speed of the motor(*255 is the max speed)]
  
  pinMode(3, OUTPUT);   //Analog right motor pin(forward). 
  pinMode(5, OUTPUT);   //Analog right motor pin(backward).
  pinMode(6, OUTPUT);   //Analog left motor pin(forward).
  pinMode(9, OUTPUT);   //Analog left motor pin(backward).
  
}

void loop(){
  int left = digitalRead(2);
  int right = digitalRead(4);

  // if both the sensor on the white the goes forward
 
  if (left == 1 && right == 1){

    analogWrite(3, 100); 
    analogWrite(5, 0);
    analogWrite(6, 100);
    analogWrite(9, 0);
  }
 
  // if the left sensor on the black line then turn left
  
  else if (left == 0 && right == 1){
    analogWrite(3, 100);
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
  }
  
  //if the right sensor on the black line the turn right

  else if (left ==1 && right ==0){
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(6, 100);
    analogWrite(9, 0);
  }
  
 // if only black then stops

 else{
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
 }
}
