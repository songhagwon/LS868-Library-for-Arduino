#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
  // 1초동안 기다립니다.
  delay(1000);
  // 1번 모터의 D 게인을 50으로 설정합니다.
  micro.setGainD(1, 50);
}


void loop() {
  // 1번 모터의 D 게인값을 시리얼로 출력합니다.
  Serial.println(micro.getGainD(1));
  // 1초동안 기다립니다.
  delay(1000);
}

