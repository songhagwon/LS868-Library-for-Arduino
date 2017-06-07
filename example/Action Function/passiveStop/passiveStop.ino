 #include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);
}

void loop() {
    // ID : 1번 모터의 회전을 즉시 정지시킵니다.
    micro.passiveStop(1);
    delay(1000);

    // 모든 모터의 회전을 즉시 정지시킵니다.
    micro.passiveStop(ALL);
    delay(1000);
}
