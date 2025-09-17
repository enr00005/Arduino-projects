#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
float distance, height, sensorHeight = 200.0; // Sensor fixed at 200 cm from ground

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  lcd.clear();

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.0343 / 2;

  // Calculate object height (assuming sensor is at 200 cm from ground)
  height = sensorHeight - distance;

  // Show results
 
  Serial.print("Object Height: ");
  Serial.print(height);
  Serial.println(" cm");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Height: ");
  lcd.setCursor(7,1);
  lcd.print(height);
  lcd.print(" cm");
  delay(500);
}
