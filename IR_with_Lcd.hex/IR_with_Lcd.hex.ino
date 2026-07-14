#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int irPin = 2;

void setup() {
  pinMode(irPin, INPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("IR Sensor");
}

void loop() {

  if (digitalRead(irPin) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Object Found  ");
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("No Object     ");
  }

  delay(100);
}