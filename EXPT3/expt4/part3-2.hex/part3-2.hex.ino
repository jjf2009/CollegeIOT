#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ledpin = 13;

void setup() {
  pinMode(ledpin, OUTPUT);
  lcd.begin(16, 2);     
}

void loop() {
  // LED ON
  digitalWrite(ledpin, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED Status:");
  lcd.setCursor(0, 1);
  lcd.print("LED ON");
  delay(3000);

  // LED OFF
  digitalWrite(ledpin, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED Status:");
  lcd.setCursor(0, 1);
  lcd.print("LED OFF");
  delay(3000);
}
