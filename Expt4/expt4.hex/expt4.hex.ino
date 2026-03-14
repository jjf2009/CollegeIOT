int ledpin=13;
int potpin=A0;
int Value;

void setup() {
  pinMode(ledpin,OUTPUT);

}

void loop() {
  Value=analogRead(potpin);
  Value=Value/4;
  analogWrite(ledpin,Value);

}
