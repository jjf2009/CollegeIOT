#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ldrPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LDR PWM");
}

void loop() {
  int ldrValue = analogRead(ldrPin);          // 0-1023
  int pwmValue = map(ldrValue, 0, 1023, 255, 0);

  analogWrite(ledPin, pwmValue);

  lcd.setCursor(0, 1);
  lcd.print("LDR:");
  lcd.print(ldrValue);
  lcd.print("   ");

  delay(100);
}



// Connections
// LDR Voltage Divider
// One end of LDR → 5V
// Other end → A0
// 10kΩ resistor from A0 → GND
// LED (+220Ω resistor) → PWM pin 9
// LCD → SDA, SCL, 5V, GND