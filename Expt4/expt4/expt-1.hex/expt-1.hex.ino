
int ledPin = 6;
int analogPin = A0;

int brightness = 0;    
int fadeAmount = 5;    



void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // Update brightness
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; 
  }
  analogWrite(ledPin, brightness);

  delay(50);
}