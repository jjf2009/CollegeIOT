#include <LiquidCrystal.h>

// LCD using analog pins as digital
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int redPins[]    = {11, 8, 5, 4};
int yellowPins[] = {12, 9, 6, 3};
int greenPins[]  = {13, 10, 7, 2};

void setup() {
  lcd.begin(16, 2);

  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }

  lcd.setCursor(0, 0);
  lcd.print("4-Way Traffic");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void allRed() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }
}

void greenPhase(int lane) {
  allRed();

  // GREEN PHASE
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Signal");
  lcd.setCursor(0, 1);
  lcd.print("Lane ");
  lcd.print(lane + 1);
  lcd.print(" GREEN");

  digitalWrite(redPins[lane], LOW);
  digitalWrite(greenPins[lane], HIGH);
  delay(3000);

  // YELLOW PHASE
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Signal");
  lcd.setCursor(0, 1);
  lcd.print("Lane ");
  lcd.print(lane + 1);
  lcd.print(" YELLOW");

  digitalWrite(greenPins[lane], LOW);
  digitalWrite(yellowPins[lane], HIGH);
  delay(2000);

  digitalWrite(yellowPins[lane], LOW);
  digitalWrite(redPins[lane], HIGH);
}

void loop() {
  for (int lane = 0; lane < 4; lane++) {
    greenPhase(lane);
  }
}
