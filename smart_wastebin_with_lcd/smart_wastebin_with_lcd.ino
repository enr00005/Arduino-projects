#include <Servo.h>
#include <LiquidCrystal.h>

// Pin Definitions
#define TRIG 9
#define ECHO 10
#define IR_SENSOR 7
#define SERVO_PIN 6

// Initialize LCD: RS=12, EN=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo lidServo;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IR_SENSOR, INPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(0); // lid closed

  lcd.begin(16, 2);
  lcd.print(" Smart Wastebin ");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration, distance;
  
  // --- Ultrasonic for hand detection ---
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  // If hand detected (within 15 cm), open lid
  if (distance > 0 && distance < 15) {
    lidServo.write(90); // open lid
    delay(3000);        // keep open for 3 sec
    lidServo.write(0);  // close lid
  }

  // --- IR Sensor for Bin Full detection ---
  int binFull = digitalRead(IR_SENSOR);

  lcd.setCursor(0, 0);
  lcd.print("Waste Level:    ");
  lcd.setCursor(0, 1);

  if (binFull == HIGH) { 
    lcd.print("  BIN IS FULL   ");
  } else {
    lcd.print("  Space Left    ");
  }

  delay(500);
}
