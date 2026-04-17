#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ledPin = 6;
int analogPin = A0;

int brightness = 0;    
int fadeAmount = 5;    

int dvalue = 0;
int fixedValue;
int fixedPercent;

void setup() {
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Analog Read: ");
}

void loop() {
  
  fixedValue = analogRead(analogPin);
  
  
  fixedPercent = map(fixedValue, 0, 1023, 0, 100);
  dvalue = map(fixedValue,0,1023,0,255);
  
  lcd.setCursor(0, 1);
  
  
  analogWrite(ledPin, brightness);
    lcd.print(brightness);
  brightness = brightness + fadeAmount;
  
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; 
  }
  
  delay(50); 
}
