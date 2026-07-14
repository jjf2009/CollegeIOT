#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int potPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("PWM Control");
}

void loop() {
  int potValue = analogRead(potPin);          // 0-1023
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, pwmValue);

  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.print(pwmValue);
  lcd.print("   "); // Clears leftover digits

  delay(100);
}