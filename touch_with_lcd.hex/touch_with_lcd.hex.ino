#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int touchPin = 2;

void setup() {
  pinMode(touchPin, INPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Touch Sensor");
}

void loop() {

  if (digitalRead(touchPin) == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("Touched      ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Not Touched  ");
  }

  delay(100);
}