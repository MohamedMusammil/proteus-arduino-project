#include <Servo.h>
#include <LiquidCrystal.h>

// Define pins for the LEDs and LCD
int greenled = 13; // Green LED pin
int redled = 12;   // Red LED pin

// Create a Servo object
Servo myServo;

// Create an LCD object (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  myServo.attach(9); // Attach the servo on pin 9
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Servo Angle:");
}

void loop() {
  // Rotate continuously in one direction (0 degrees)
  myServo.write(0); // Set speed and direction
  digitalWrite(greenled, LOW);
  digitalWrite(redled, LOW);
  
  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print("Angle:   "); // Clear previous angle display
  lcd.print("0"); // Display current angle
  delay(1000); // Rotate for 1 second

  // Rotate to position (90 degrees)
  myServo.write(90); // Set speed and direction
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
  
  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print("Angle:   "); // Clear previous angle display
  lcd.print("90"); // Display current angle
  delay(1000); // Rotate for 1 second

  // Rotate continuously in the opposite direction (180 degrees)
  myServo.write(180); // Set speed and direction
  digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
  
  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print("Angle:   "); // Clear previous angle display
  lcd.print("180"); // Display current angle
  delay(1000); // Rotate for 1 second
}