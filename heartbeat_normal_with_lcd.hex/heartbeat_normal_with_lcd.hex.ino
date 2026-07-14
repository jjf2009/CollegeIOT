#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0;

double alpha = 0.75;
int period = 100;

void setup() {
  Wire.begin();

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Heart Monitor");
}

void loop() {

  static double oldValue = 0;

  int rawValue = analogRead(sensorPin);

  double value = alpha * oldValue + (1 - alpha) * rawValue;

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("  Filtered: ");
  Serial.println(value);

  lcd.setCursor(0,1);
  lcd.print("Val:");
  lcd.print((int)value);
  lcd.print("    ");

  oldValue = value;

  delay(period);
}