#include "Servo.h"
int servoPin = 9;
int rightButtonPin = 12;
int leftButtonPin = 13;
int servoAngle = 90;
int rightButtonState = 0;
int leftButtonState = 0;
Servo myservo;

void setup() {
  pinMode(rightButtonPin, INPUT);
  pinMode(leftButtonPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(servoAngle);
  Serial.begin(9600);
}

void loop() {
  rightButtonState = digitalRead(rightButtonPin);
  leftButtonState = digitalRead(leftButtonPin);
    
  if(rightButtonState == 1) {
    if(servoAngle > 0) {
      myservo.write(servoAngle);
      Serial.print("right button : ");
      Serial.println(servoAngle);
      servoAngle--;
      delay(15);
    }
  }

  if(leftButtonState == 1) {
    if(servoAngle < 180) {
      myservo.write(servoAngle);
      Serial.print("left button : ");
      Serial.println(servoAngle);
      servoAngle++;
      delay(15);
    }
  }
}
