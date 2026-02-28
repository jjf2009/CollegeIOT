#include <LiquidCrystal.h>

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int redPins[]    = {11, 8, 5, 4};
int yellowPins[] = {12, 9, 6, 3};
int greenPins[]  = {13, 10, 7, 2};

const int greenTime = 5;   // seconds
const int yellowTime = 3;  // seconds

void setup() {
  lcd.begin(16, 2);

  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }

  allRed();
}

void allRed() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }
}

void displayStatus(int activeLane, char phase, int activeTimer, int stopTimer) {
  lcd.clear();

  for (int i = 0; i < 4; i++) {
    int row = (i < 2) ? 0 : 1;
    int col = (i % 2) * 8;

    lcd.setCursor(col, row);
    lcd.print("L");
    lcd.print(i + 1);

    if (i == activeLane) {
      lcd.print(phase);
      if (activeTimer < 10) lcd.print("0");
      lcd.print(activeTimer);
    } else {
      lcd.print("S");
      if (stopTimer < 10) lcd.print("0");
      lcd.print(stopTimer);
    }
  }
}

void greenPhase(int lane) {
  allRed();

  digitalWrite(redPins[lane], LOW);
  digitalWrite(greenPins[lane], HIGH);

  int stopDuration = greenTime + yellowTime;

  for (int t = greenTime; t > 0; t--) {
    displayStatus(lane, 'G', t, stopDuration - (greenTime - t));
    delay(1000);
  }

  digitalWrite(greenPins[lane], LOW);
  digitalWrite(yellowPins[lane], HIGH);

  for (int t = yellowTime; t > 0; t--) {
    displayStatus(lane, 'Y', t, yellowTime - (yellowTime - t));
    delay(1000);
  }

  digitalWrite(yellowPins[lane], LOW);
  digitalWrite(redPins[lane], HIGH);
}

void loop() {
  for (int lane = 0; lane < 4; lane++) {
    greenPhase(lane);
  }
}
