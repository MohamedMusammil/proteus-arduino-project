// DEFINE PINS FOR EACH SEGMENT (A TO G)
const int segmentpins[] = {7, 6, 5, 4, 3, 2, 1}; // a, b, c, d, e, f, g

// Digit encoding for a common cathode 7-segment display
// Each digit is represented as a binary pattern for segment a-g
const byte digitCodes[] = {
    // 0b1111110, // 0
    // 0b0110000, // 1
    // 0b1101101, // 2
    // 0b1111001, // 3
    // 0b0110011, // 4
    // 0b1011011, // 5
    // 0b1011111, // 6
    // 0b1110000, // 7
    // 0b1111111, // 8
    // 0b1110011  // 9
    ob1110111
};

void setup() {
    // Set all segment pins as output
    for (int i = 0; i < 7; i++) {
        pinMode(segmentpins[i], OUTPUT);
    }
}

void loop() {
    for (int digit = 0; digit <= 9; digit++) {
        displayDigit(digit); // Display the current digit
        delay(200);         // Wait for 1 second
    }
}

void displayDigit(int digit) {
    byte segments = digitCodes[digit]; // Get the binary pattern for the digit

    for (int i = 0; i < 7; i++) {
        // Set each segment high or low based on the binary pattern
        digitalWrite(segmentpins[i], (segments >> (6 - i)) & 0x01);
    }
}