#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Define pin numbers for LEDs and Buzzer
const int redLEDPin = 7;     // Pin for Red LED
const int greenLEDPin = 6;   // Pin for Green LED
const int buzzerPin = 5;     // Pin for Buzzer

int lm35pin = A0; // LM35 output connected to analog pin A0
float temperature;

void setup() {
    lcd.begin(16, 2); // Set up the LCD's number of columns and rows
    pinMode(lm35pin, INPUT); // Set LM35 pin as input
    pinMode(redLEDPin, OUTPUT); // Set Red LED pin as output
    pinMode(greenLEDPin, OUTPUT); // Set Green LED pin as output
    pinMode(buzzerPin, OUTPUT); // Set Buzzer pin as output
}

void loop() {
    int sensorValue = analogRead(lm35pin); // Read the input on analog pin A0
    
    // Convert the analog reading to temperature in Celsius
    temperature = (sensorValue * 5.0 * 100.0) / 1024.0;

    lcd.clear(); // Clear the LCD before displaying new data
    lcd.setCursor(0, 0);
    lcd.print("Temp: "); 
    lcd.print(temperature); 
    lcd.print(" C");

    // Control LEDs and Buzzer based on temperature conditions
    if (temperature > 30) {
        // Conditions for HOT
        lcd.setCursor(0, 1);
        lcd.print("Status: HOT   ");
        
        digitalWrite(redLEDPin, HIGH);   // Turn on Red LED
        digitalWrite(greenLEDPin, LOW);   // Ensure Green LED is off
        
        tone(buzzerPin, 1000);            // Activate buzzer at 1000 Hz
        delay(500);
        digitalWrite(redLEDPin, LOW);     // Turn off Red LED
        noTone(buzzerPin);                 // Turn off buzzer
        delay(500);
        
    } else {
        // Conditions for NORMAL
        lcd.setCursor(0, 1);
        lcd.print("Status: NORMAL ");
        
        digitalWrite(redLEDPin, LOW);      // Ensure Red LED is off
        digitalWrite(greenLEDPin, LOW);    // Ensure Green LED is off
        
        if (temperature < 30) {
            digitalWrite(greenLEDPin, HIGH); // Turn on Green LED
            tone(buzzerPin, 500);             // Activate buzzer at 500 Hz for normal condition
            delay(500);
            digitalWrite(greenLEDPin, LOW);   // Turn off Green LED
            noTone(buzzerPin);                 // Turn off buzzer
            delay(500);
        }
    }

    delay(2000); // Wait for 2 seconds before next reading
}