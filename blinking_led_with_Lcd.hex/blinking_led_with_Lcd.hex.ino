#include<Wire.h>
#include<LiquidCrystal_I2C.h>
int ledpin=13;

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  pinMode(ledpin,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello World!");
}

void loop() {
  digitalWrite(ledpin,HIGH);
  lcd.setCursor(0,1);
  lcd.print("LED: ON ");
  delay(1000);
  digitalWrite(ledpin,LOW);
  lcd.setCursor(0,1);
  lcd.print("LED: OFF");

  delay(1000);

}
