#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LDR_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  analogReadResolution(10);   // Force 0-1023 range

  lcd.init();
  lcd.backlight();
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  Serial.println(ldrValue);

  lcd.setCursor(0, 0);
  lcd.print("LDR Value:     ");

  lcd.setCursor(0, 1);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);

  delay(500);
}