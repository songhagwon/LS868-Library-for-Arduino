#include <LS868.h>

LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 엽니다.
  micro.begin(1000000);
}

void loop() {
  // 1번 모터의 ID 값을 시리얼로 출력합니다.
  Serial.println(micro.getModuleID(1));
  // 1초 동안 기다립니다.
  delay(1000);
}   
