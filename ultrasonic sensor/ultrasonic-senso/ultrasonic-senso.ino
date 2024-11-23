#include <LiquidCrystal.h>

// Initialize the LCD with the specified pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7

int trigPin = 7; 
int echoPin = 6; 
int buzzerPin = 5; 

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Set the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set up the buzzer pin
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Distance variables
  long duration;
  float distanceCm;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time for which the echo pin is HIGH
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distanceCm = duration * 0.034 / 2;

  // Clear the previous content on the LCD
  lcd.clear();

  // Set cursor to first column of first row
  lcd.setCursor(0, 0); 
  lcd.print("Distance:");

  // Set cursor to first column of second row
  lcd.setCursor(0, 1); 
  lcd.print(distanceCm); 
  lcd.print(" cm");       

  // Check if distance is greater than 100 cm
  if (distanceCm > 100) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);                     
    digitalWrite(buzzerPin, LOW);   
    delay(500);                     
  }


  delay(500); 
}