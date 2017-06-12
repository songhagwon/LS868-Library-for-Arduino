/*
 * getLEDValue() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // 1번 모터의 LED를 R : 100, G : 250, B : 50으로 설정합니다.
  micro.LEDControl(1, 100, 250, 50);
  // 1번 모터의 빨간색 값을 시리얼로 출력합니다.
  Serial.println(micro.getLEDValue(1, RED));
  // 1번 모터의 초록색 값을 시리얼로 출력합니다.
  Serial.println(micro.getLEDValue(1, GREEN));
  // 1번 모터의 파란색 값을 시리얼로 출력합니다.
  Serial.println(micro.getLEDValue(1, BLUE));
  // 1초 동안 기다립니다.
  delay(1000);
}
