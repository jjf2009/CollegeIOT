
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int redPins[]    = {11, 8, 5, 4};
int yellowPins[] = {12, 9, 6, 3};
int greenPins[]  = {13, 10, 7, 2};
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("OLED Connected");
  display.display();
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

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Traffic Signal");
  display.print("Lane ");
  display.print(lane + 1);
  display.println(" GREEN");
  display.display();

  digitalWrite(redPins[lane], LOW);
  digitalWrite(greenPins[lane], HIGH);
  delay(3000);

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Lane ");
  display.print(lane + 1);
  display.println(" YELLOW");
  display.display();

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
