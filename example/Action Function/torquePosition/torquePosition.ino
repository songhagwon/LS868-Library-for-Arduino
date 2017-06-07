#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // 1번 아이디 모터를 최대 토크 대비 50%의 토크를 이용하여 -500 위치로 이동합니다.
  micro.torquePosition(1, 50, -500);
  delay(1000);

  // 1번 아이디 모터를 최대 토크 대비 100%의 토크를 이용하여 500 위치로 이동합니다.
  micro.torquePosition(ALL, 100, 500);
  delay(1000);
}



