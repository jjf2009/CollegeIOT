#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   // Adjust pins if needed

void setup() {
  pinMode(13, OUTPUT);  // Red
  pinMode(12, OUTPUT);  // Yellow
  pinMode(8, OUTPUT);   // Green
  
  lcd.begin(16, 2);
  lcd.print("Traffic System");
  delay(2000);
  lcd.clear();
}

void loop() {

  // GREEN LIGHT
  digitalWrite(8, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("GREEN - GO");
  delay(500);
  digitalWrite(8, LOW);
  delay(500);

  // YELLOW LIGHT
  digitalWrite(12, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("YELLOW - WAIT");
  delay(500);
  digitalWrite(12, LOW);
  delay(500);

  // RED LIGHT
  digitalWrite(13, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("RED - STOP");
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
