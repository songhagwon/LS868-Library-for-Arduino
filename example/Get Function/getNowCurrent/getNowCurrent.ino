#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // LSM_micro 모터를 토크 - 포지션모드로 제어합니다.
  micro.torquePosition(1, i * 10, -200 + i * 50);
  // 0.005초동안 기다립니다.
  delay(5);
  // 1번 모터의 현재 전류값을 시리얼로 출력합니다.
  Serial.println(micro.getNowCurrent(1));
  // 0.5초동안 기다립니다.
  delay(500);
}

