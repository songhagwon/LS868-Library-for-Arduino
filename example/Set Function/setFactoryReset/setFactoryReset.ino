/*
 * setFactoryReset() 함수 사용 예시
 */
#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);
    // 1번 모터를 공장 초기화 상태로 설정합니다.
    micro.setFactoryReset(1);
}

void loop() {
  
}
