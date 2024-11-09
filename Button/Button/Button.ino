int buttonpin = 2;
int ledpin = 13;
int buttonstate = 0;

void setup() {
  pinMode(ledpin, OUTPUT );

  pinMode(buttonpin, INPUT_PULLUP); 

}

void loop() {
  buttonstate = digitalRead(buttonpin);

  if (buttonstate == LOW) {
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

}
