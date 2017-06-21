/*
 * getNowPosition() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 micro을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  micro.begin(1000000);
  // 1번 모터가 50%의 속력과 CW 방향으로 회전합니다.
  micro.wheelMode(1, 50, CCW);
}

void loop() {
  // 1번 모터의 현재 step값을 시리얼로 출력합니다.
  Serial.print(micro.getNowPosition(1));
  // 0.1초 동안 기다립니다.
  delay(100);
}
