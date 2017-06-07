#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);
    // 입력한 아이디와 일치하는 모듈을 공장초기화 상태로 되돌립니다.
    micro.setFactoryReset(1);
    delay(5);
    // 연결되어 있는 모든 모듈을 공장초기화 상태로 되돌립니다.
    micro.setFactoryReset(ALL);
}

void loop() {
  
}

