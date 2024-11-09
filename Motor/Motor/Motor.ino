#include <Servo.h> // Include the Servo library
Servo myServo; // Create a servo object

void setup() {
  myServo.attach(9); // Attach the servo on pin 9
}

void loop() {
  //rotate continuously in one direction
  myServo.write(0); //set speed and direction
  delay(2000); //rotate for 2 seconds

  //stop the servo
  myServo.write(90);
  delay(1000);//hold for 1 second

  //rotate continuously in the opposite direction
  myServo.write(180);
  delay(2000);

}