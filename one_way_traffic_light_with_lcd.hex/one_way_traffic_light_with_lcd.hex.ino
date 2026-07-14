#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int RED = 8;
const int YELLOW = 9;
const int GREEN = 10;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  Wire.begin();

  lcd.init();
  lcd.backlight();
}

void loop() {

  // RED
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("STOP");

  delay(5000);

  // GREEN
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("GO");

  delay(5000);

  // YELLOW
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("WAIT");

  delay(2000);
}