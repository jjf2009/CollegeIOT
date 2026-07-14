#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// North
const int NR = 2;
const int NY = 3;
const int NG = 4;

// East
const int ER = 5;
const int EY = 6;
const int EG = 7;

// South
const int SR = 8;
const int SY = 9;
const int SG = 10;

// West
const int WR = 11;
const int WY = 12;
const int WG = 13;

void setup() {

  pinMode(NR, OUTPUT);
  pinMode(NY, OUTPUT);
  pinMode(NG, OUTPUT);

  pinMode(ER, OUTPUT);
  pinMode(EY, OUTPUT);
  pinMode(EG, OUTPUT);

  pinMode(SR, OUTPUT);
  pinMode(SY, OUTPUT);
  pinMode(SG, OUTPUT);

  pinMode(WR, OUTPUT);
  pinMode(WY, OUTPUT);
  pinMode(WG, OUTPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();
}

void allRed() {
  digitalWrite(NR, HIGH);
  digitalWrite(ER, HIGH);
  digitalWrite(SR, HIGH);
  digitalWrite(WR, HIGH);

  digitalWrite(NY, LOW);
  digitalWrite(EY, LOW);
  digitalWrite(SY, LOW);
  digitalWrite(WY, LOW);

  digitalWrite(NG, LOW);
  digitalWrite(EG, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(WG, LOW);
}

void loop() {

  // ---------- NORTH ----------
  allRed();
  digitalWrite(NR, LOW);
  digitalWrite(NG, HIGH);

  lcd.clear();
  lcd.print("North : GO");
  lcd.setCursor(0,1);
  lcd.print("Others: STOP");

  delay(5000);

  digitalWrite(NG, LOW);
  digitalWrite(NY, HIGH);

  lcd.clear();
  lcd.print("North: WAIT");

  delay(2000);

  // ---------- EAST ----------
  allRed();
  digitalWrite(ER, LOW);
  digitalWrite(EG, HIGH);

  lcd.clear();
  lcd.print("East : GO");
  lcd.setCursor(0,1);
  lcd.print("Others: STOP");

  delay(5000);

  digitalWrite(EG, LOW);
  digitalWrite(EY, HIGH);

  lcd.clear();
  lcd.print("East: WAIT");

  delay(2000);

  // ---------- SOUTH ----------
  allRed();
  digitalWrite(SR, LOW);
  digitalWrite(SG, HIGH);

  lcd.clear();
  lcd.print("South : GO");
  lcd.setCursor(0,1);
  lcd.print("Others: STOP");

  delay(5000);

  digitalWrite(SG, LOW);
  digitalWrite(SY, HIGH);

  lcd.clear();
  lcd.print("South: WAIT");

  delay(2000);

  // ---------- WEST ----------
  allRed();
  digitalWrite(WR, LOW);
  digitalWrite(WG, HIGH);

  lcd.clear();
  lcd.print("West : GO");
  lcd.setCursor(0,1);
  lcd.print("Others: STOP");

  delay(5000);

  digitalWrite(WG, LOW);
  digitalWrite(WY, HIGH);

  lcd.clear();
  lcd.print("West: WAIT");

  delay(2000);
}