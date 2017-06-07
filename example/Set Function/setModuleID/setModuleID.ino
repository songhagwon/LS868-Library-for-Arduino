#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);
    // 아이디 변경 후 확인하는 예제1 입니다.
    micro.setModuleID(1, 2);     // 파라미터 1번은 변경을 원하는 아이디, 파라미터 2번은 변경할 아이디를 입력합니다.
    delay(5)
    Serial.println(micro.getModuleID(2));
    delay(100);
    
    // 아이디 변경 후 확인하는 예제2 입니다.
    micro.setModuleID(ALL, 3); // 파라미터 1번은 모든 모듈을 호출하는 형식, 파라미터 2번은 변경할 아이디를 입력합니다.
    delay(5)
    Serial.println(micro.getModuleID(3));
    delay(100);
}


void loop() {
  
}
