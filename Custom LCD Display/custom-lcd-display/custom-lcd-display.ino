#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7

byte smiley[8] = {
  B00000,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};
byte letter[8] = {
  B00000,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, smiley);
  lcd.createChar(1, letter);

  lcd.setCursor(0, 0);
  lcd.write(byte(0));

   lcd.setCursor(1, 1);
  lcd.write(byte(1));
}

void loop() { }