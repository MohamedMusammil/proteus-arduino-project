void setup() {
  pinMode(13, OUTPUT); 
}

void loop() {
  int ldr_value = analogRead(A0); 

  if (ldr_value < 50) {
    digitalWrite(13, HIGH); 
  } else {
    digitalWrite(13, LOW); 
  }
}