// 예제 01 서보 모터를 왼쪽, 오른쪽으로 180도 이동
#include "Servo.h"    //서보모터 라이브러리 가져옴
 
Servo servo;    //서보모터 객체 선언
int servoPin = 9;    //서보모터 제어핀 할당
 
void setup()
{
    Serial.begin(9600);
    servo.attach(servoPin);    //서보모터 핀 연결
}
 
void loop()
{
    int angle;    //각도 변수 선언
 
    //0 -> 180도로 서보모터 움직임
    for (angle = 0; angle < 180; angle++)
    {
        servo.write(angle);    //angle(각도)값으로 서보모터 제어
        Serial.print("right angle : ");
        Serial.println(angle); //각도 값 출력
        delay(10);             //delay로 각도의 변화 속도를 조절
    }
    //180 -> 0도로 서보모터 움직임
    for (angle = 180; angle > 0; angle--)
    {
        servo.write(angle); //angle(각도)값으로 서보모터 제어
        Serial.print("left angle : ");
        Serial.println(angle); //각도 값 출력
        delay(10);             //delay로 각도의 변화 속도를 조절
    }
}
