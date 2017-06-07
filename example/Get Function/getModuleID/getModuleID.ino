/*
   LS868 시리즈의 모듈 아이디를 확인하는 함수입니다.
   2017. 03. 23 작성
*/

#include <LS868.h>

LS868 micro(LSM_MICRO, HARD_SERIAL);

void setup() {
  // 통신속도를 115200 bps로 설정하여 시리얼을 엽니다.
  micro.begin(115200);
  Serial.begin(115200);
}

void loop() {
  // 1 ~ 253의 숫자를 입력하여 모듈의 ID를 확인할 수 있습니다.
  Serial.println(micro.getModuleID(1));   // 1번 모듈의 ID값을 확인합니다.
  delay(1000);                             // 1초동안 대기합니다.
}   
