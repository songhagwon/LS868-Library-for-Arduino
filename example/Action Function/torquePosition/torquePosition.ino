/*
 * torquePosition() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // 1번 모터가 50%의 토크를 이용하여 -500 step으로 이동합니다.
  micro.torquePosition(1, 50, -500);
  // 1초동안 기다립니다.
  delay(1000);

  // 모든 모터가 100%의 토크를 이용하여 500step으로 이동합니다.
  micro.torquePosition(ALL, 100, 500);
  // 1초동안 기다립니다.
  delay(1000);
}
