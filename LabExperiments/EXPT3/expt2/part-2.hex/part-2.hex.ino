int redPins[]    = {11, 8, 5, 4};
int yellowPins[] = {12, 9, 6, 3};
int greenPins[]  = {13, 10, 7, 2};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }
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
  digitalWrite(redPins[lane], LOW);
  digitalWrite(greenPins[lane], HIGH);
  delay(3000);

  digitalWrite(greenPins[lane], LOW);
  digitalWrite(yellowPins[lane], HIGH);
  delay(3000);

  digitalWrite(yellowPins[lane], LOW);
  digitalWrite(redPins[lane], HIGH);
}

void loop() {
  for (int lane = 0; lane < 4; lane++) {
    greenPhase(lane);
  }
}
