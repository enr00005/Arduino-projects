#include <DHT.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(5,DHT11);
void setup() {
  pinMode(2,OUTPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2,HIGH);
  float temp=dht.readTemperature();
  float humid=dht.readHumidity();
  Serial.println(temp);
  Serial.println(humid);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP");
  lcd.setCursor(6,0);
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY");
  lcd.setCursor(10,1);
  lcd.print(humid);
  delay(1000);
}
