 #include <LS868.h>

// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.
LS868 micro(MICRO, HARD_SERIAL);

void setup() {
    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.
    micro.begin(1000000);
}

void loop() {
    // ID : 1번 모터의 LED를 R:50, G:50, B:0의 값으로 제어합니다.
    micro.speedPosition(1, 50, 50, 0);
    delay(1000);

    // 모든 모터의 LED를 R:0, G:250, B:0의 값으로 제어합니다.
    micro.speedPosition(ALL, 0, 250, 0);
    delay(1000);
}




