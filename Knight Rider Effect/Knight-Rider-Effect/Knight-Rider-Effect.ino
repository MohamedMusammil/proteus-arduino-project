int timer = 35;

void setup() {
  for (int thispin = 6; thispin <= 13; thispin++) {
    
    pinMode(thispin, OUTPUT);
  }
}

void loop() {
  for (int thispin = 6; thispin <= 13; thispin++) {
  digitalWrite(thispin, HIGH);
  delay(timer);
  digitalWrite(thispin, LOW);
  }

  for (int thispin = 13; thispin > 6; thispin--) {
  digitalWrite(thispin, HIGH);
  delay(timer);
  digitalWrite(thispin, LOW);
  }

}
