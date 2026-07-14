#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

const int potPin = A0;

void setup() {
  Wire.begin();

  lcd.init();
  lcd.backlight();

  servo.attach(9);

  lcd.setCursor(0,0);
  lcd.print("Servo Control");
}

void loop() {
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 1023, 0, 180);

  servo.write(angle);

  lcd.setCursor(0,1);
  lcd.print("Angle: ");
  lcd.print(angle);
  lcd.print((char)223);   // Degree symbol
  lcd.print("   ");

  delay(100);
}