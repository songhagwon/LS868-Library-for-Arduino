#include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(LSM_MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
  micro.begin(1000000);
}

void loop() {
  // 0 ~ 253의 숫자를 입력하여 해당 아이디와 일치하는 모듈의 펌웨어 번호를 출력합니다.
  Serial.println(micro.getFirmwareVersion(1));
  delay(1000);
}
