#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int ledpin = 6;
int potpin = A0;
float Value;

void setup() {
  pinMode(ledpin, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  Value = analogRead(potpin);
   int value = map(Value,0,402,0,100);

  lcd.setCursor(0, 0);
  lcd.print("LED Brightness:");

  // Clear previous value area
  lcd.setCursor(0, 1);
  lcd.print("                ");  // clear full line

  // Print updated value
  lcd.setCursor(0, 1);
  lcd.print(value);
  lcd.print("%");

  delay(100);
}