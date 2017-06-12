/*
 * setBaudRate() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
  // 1번 모터의 통신속도를 115,200bps로 변경합니다.
  micro.setBaudRate(1, 115200);
}

void loop() {
  /* 
   * 통신속도 변경 후 아두이노 통신속도를
   * 모터속도와 일치하게 다시 설정해서 실행하시기 바랍니다.
   */

  // 1번 모터의 통신속도를 시리얼로 출력합니다.
  Serial.println(micro.getBaudRate(1));
  // 1초 동안 기다립니다.
  delay(1000);
}
