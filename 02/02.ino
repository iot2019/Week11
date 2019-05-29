// 실습 02 : 가변저항을 이용한 서보모터 제어 응용

#include "Servo.h" // 서보 라이브러리를 불러옴
Servo servo; // Servo 클래스의 객체 servo 생성
int potentioMeterPin = 0;//가변저항기에 연결한 아날로그 핀의 번호를 설정
int servoPin = 9;  // 서보모터의 핀 

void setup() {
  servo.attach(servoPin); // 서보를 사용하는 핀으로 디지털 핀9번을 설정
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(potentioMeterPin); //가변저항의 값을 읽어들임 
  int angle = map(value,0,1023,0,179);//읽어 들인 값을 0에서 179까지 변환
  Serial.print("angle : ");
  Serial.println(angle);
  servo.write(angle); //서보의 각도를 설정
  delay(15); // 서보가 지정한 각도까지 움직이는 동안 대기
}
