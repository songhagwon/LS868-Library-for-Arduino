/*
 * passiveStop() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // 1번 모터가 100%의 속력과 CW 방향으로 회전합니다.
  micro.wheelMode(1, 100, CW);
  // 1초동안 기다립니다.
  delay(1000);

  // 모든 모터의 토크를 풀어버립니다.
  micro.passiveStop(ALL);
  // 1초동안 기다립니다.
  delay(1000);
}
