#include <LiquidCrystal.h>

// Initialize LCD with pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int IRSensor = 7; // connect IR sensor module to Arduino pin D7
int buzzer = 1;    // connect buzzer to pin D6
int pinkLED = 6;   // connect pink LED to pin D4
int yellowLED = 5; // connect yellow LED to pin D5

void setup() {
    lcd.begin(16, 2); // Initialize LCD
    pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
    pinMode(buzzer, OUTPUT); // Buzzer OUTPUT
    pinMode(pinkLED, OUTPUT); // Pink LED OUTPUT
    pinMode(yellowLED, OUTPUT); // Yellow LED OUTPUT

    lcd.print("Detecting..."); // Initial message on LCD
    lcd.setCursor(0, 1);
}

void loop() {
    int sensorStatus = digitalRead(IRSensor); // Read IR sensor status

    if (sensorStatus == HIGH) { // Check if an object is detected
        lcd.clear(); // Clear previous message
        lcd.print("Object Detected!"); // Display object detected message
        
        digitalWrite(yellowLED, HIGH); // Turn on yellow LED
        digitalWrite(pinkLED, LOW); // Turn off pink LED
        digitalWrite(buzzer, HIGH); // Turn on buzzer
        
        delay(500); // Keep LED and buzzer active for a moment
        
    } else {
        lcd.clear(); // Clear previous message
        lcd.print("Detecting..."); // Display detecting message
        
        digitalWrite(pinkLED, HIGH); // Blink pink LED
        digitalWrite(yellowLED, LOW); // Turn off yellow LED
        digitalWrite(buzzer, LOW); // Turn off buzzer
        
        delay(500);
        
        digitalWrite(pinkLED, LOW); // Turn off pink LED for next blink
        delay(500);
    }
}