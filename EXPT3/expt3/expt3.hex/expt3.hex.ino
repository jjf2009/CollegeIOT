#include <LiquidCrystal.h>

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

int redPins[]    = {11, 8, 5, 4};
int yellowPins[] = {12, 9, 6, 3};
int greenPins[]  = {13, 10, 7, 2};

const int Time = 3;

void setup() {
  lcd.begin(16, 2);
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i],    OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i],  OUTPUT);
  }
  allRed();
}

void allRed() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(redPins[i],    HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i],  LOW);
  }
}

// Now accepts a per-lane stop timer array instead of one shared value
void displayStatus(int activeLane, char phase, int activeTimer, int stopTimers[]) {
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
      if (stopTimers[i] < 10) lcd.print("0");
      lcd.print(stopTimers[i]);
    }
  }
}

void greenPhase(int lane) {
  allRed();
  digitalWrite(redPins[lane],  LOW);
  digitalWrite(greenPins[lane], HIGH);

  // GREEN phase
  for (int t = Time; t > 0; t--) {
    int stopTimers[4];
    for (int i = 0; i < 4; i++) {
      if (i == lane) {
        stopTimers[i] = t;
      } else {
        // offset = how many lanes away this lane is in the queue
        int offset = (i - lane + 4) % 4;
        // wait = remaining green (t) + yellow of active (Time)
        //      + full cycles of all lanes in between ((offset-1) * 2 * Time)
        stopTimers[i] = t + Time + (offset - 1) * 2 * Time;
      }
    }
    displayStatus(lane, 'G', t, stopTimers);
    delay(1000);
  }

  digitalWrite(greenPins[lane],  LOW);
  digitalWrite(yellowPins[lane], HIGH);

  // YELLOW phase
  for (int t = Time; t > 0; t--) {
    int stopTimers[4];
    for (int i = 0; i < 4; i++) {
      if (i == lane) {
        stopTimers[i] = t;
      } else {
        int offset = (i - lane + 4) % 4;
        // wait = remaining yellow (t)
        //      + full cycles of all lanes in between ((offset-1) * 2 * Time)
        stopTimers[i] = t + (offset - 1) * 2 * Time;
      }
    }
    displayStatus(lane, 'Y', t, stopTimers);
    delay(1000);
  }

  digitalWrite(yellowPins[lane], LOW);
  digitalWrite(redPins[lane],    HIGH);
}

void loop() {
  for (int lane = 0; lane < 4; lane++) {
    greenPhase(lane);
  }
}
