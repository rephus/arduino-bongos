#include <Joystick.h>

Joystick_ Joystick;

// Based on Knock sensor by David Cuartielles https://www.arduino.cc/en/Tutorial/BuiltInExamples/Knock
// Based on JoystickButton by Matthew Heironimus

// these constants won't change:
const int sensorRight = A0;  // the piezo is connected to analog pin 0
const int sensorLeft = A1;  // the piezo is connected to analog pin 0
const int sensorClapAnalog = A2; 

const int threshold = 500;   // threshold value to decide when is a knock or not
const int clap_threshold = 500;   // threshold value to decide when is a clap sound or not
const int input_delay = 50;

// these variables will change:
int readingRight = 0;  // variable to store the value read from the sensor pin
int readingLeft = 0;  // variable to store the value read from the sensor pin
int readingClapAnal= 0;

void setup() {
  Serial.begin(9600);       // use the serial port
  Serial.println("Game start!");
  Joystick.begin();
}


void loop() {

    readingClapAnal = analogRead(sensorClapAnalog);
    if (readingClapAnal < clap_threshold) {
      Serial.print("Clap ");
      Serial.println(readingClapAnal);
      Joystick.setButton(2, 1);
        delay(input_delay);

    } else {
      Joystick.setButton(2, 0);
    }

  readingRight = analogRead(sensorRight);

  if (readingRight >= threshold) {
    Serial.println("Knock right!");
    Joystick.setButton(1, 1);
      delay(input_delay);

  } else {
    Joystick.setButton(1, 0);

  }
    readingLeft = analogRead(sensorLeft);

if (readingLeft >= threshold) {
    Serial.println("Knock left!");
    Joystick.setButton(0, 1);
      delay(input_delay);

  } else {
    Joystick.setButton(0, 0);
  }

}
