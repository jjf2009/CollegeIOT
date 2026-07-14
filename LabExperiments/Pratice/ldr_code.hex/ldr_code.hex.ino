#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDR_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LDR Sensor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  lcd.setCursor(0, 0);
  lcd.print("Light Value:");

  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear line
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);

  delay(500);
}