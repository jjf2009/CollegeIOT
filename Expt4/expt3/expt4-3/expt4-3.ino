#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int ledpin = 6;
int potpin=A0;
int Value;
void setup() {
  pinMode(ledpin,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  Value = analogRead(potpin);
  analogWrite(ledpin, Value);
  lcd.setCursor(0, 0);
  lcd.print("LED Brightness: ");   // fixed caps too
  lcd.setCursor(0, 1);
  lcd.print(Value);
  lcd.print("  ");                // trailing spaces clear leftover digits
  delay(100);
}
