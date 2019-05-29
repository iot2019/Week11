// 실습 03 : 조도 센서를 이용한 서보 모터 제어 응용
#include "Servo.h"

Servo myservo;  // Servo 클래스의 객체 myservo 생성

int potPin = 0;  // 조도센서에 연결할 아날로그 핀 A0
int servoPin = 9;
int val;    // 아날로그 핀으로 부터 읽은 값을 저장할 변수

void setup() {
  myservo.attach(servoPin);  // Servo 객체에 3번 핀 연결
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);        // 조도센서의 값을 읽 (0~1023)
  val = map(val, 0, 1023, 0, 179); // 서보모터에 사용을 위해 조도센서 값 변환(0~179)
  Serial.print("val : ");
  Serial.println(val);
  myservo.write(val);              // 변환된 값으로 서보모터 위치 변경
  delay(15);                       // 서보모터 위치 변경을 위해 기다림
}
