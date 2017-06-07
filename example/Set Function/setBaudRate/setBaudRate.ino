 #include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);

    // 변경한 최소위치값을 확인하는 예제1 입니다.
    micro.setBaudRate(1, 115200)    // 파라미터 1번은 변경을 원하는 아이디, 파라미터 2번은 변경할 통신속도입니다.
    delay(5);
    micro.begin(115200);
    Serial.println(micro.getBaudRate(1));
    delay(1000);

    // 변경한 최소위치값을 확인하는 예제2 입니다.
    micro.setBaudRate(ALL, 9600); // 파라미터 1번은 모든 모듈을 호출하는 형식, 파라미터 2번은 변경할 통신속도입니다.
    delay(5);
    micro.begin(9600);
    Serial.println(micro.getBaudRate(1));
}

void loop() {


}


