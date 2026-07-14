#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

void setup() {
  Wire.begin();

  lcd.init();
  lcd.backlight();

  servo.attach(9);

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Servo Control");
  lcd.setCursor(0,1);
  lcd.print("Enter Angle");
}

void loop() {

  if (Serial.available()) {

    int angle = Serial.parseInt();

    if (angle >= 0 && angle <= 180) {

      servo.write(angle);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Servo Angle");

      lcd.setCursor(0,1);
      lcd.print(angle);
      lcd.print((char)223);

      Serial.print("Angle: ");
      Serial.println(angle);
    }

    while (Serial.available())
      Serial.read();
  }
}