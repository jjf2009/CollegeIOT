#include <Wire.h>
#include<LiquidCrystal_I2C.h>

const int RED = 8;
const int YELLOW=9;
const int GREEN = 10;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup{
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello World")
}

void loop{
    digitalWrite(RED,HIGH);
    digitalWrite(YELLOW,LOW);
    digitalWrite(GREEN,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Traffic Ligjt");
    lcd.setCursor(0, 1);
    lcd.print("STOP");

    digitalWrite(RED,HIGH);
    digitalWrite(YELLOW,LOW);
    digitalWrite(GREEN,LOW);
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("GO");


  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("WAIT");

  delay(2000);
}