#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ldrPin = A0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("LDR Sensor");
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH);

    lcd.setCursor(0,1);
    lcd.print("LED: ON ");
  }
  else {
    digitalWrite(ledPin, LOW);

    lcd.setCursor(0,1);
    lcd.print("LED: OFF");
  }

  delay(100);
}