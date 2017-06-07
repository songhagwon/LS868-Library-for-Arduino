 #include <LS868.h>




// LSM_micro 모터와 Serial을 사용하는 생성자를 선언합니다.

LS868 micro(LSM_MICRO, HARD_SERIAL);




void setup() {

    // 통신속도를 1000000 bps로 설정하여 시리얼을 시작합니다.

    micro.begin(1000000);

}




void loop() {

    for(int i = 0; i < 10; i++) {
        // LSM_micro 모터를 토크 - 포지션모드로 제어합니다.
        micro.torquePosition(1, i*10, 0);
        // 모터와의 원활한 통신을 위해 0.005초동안 기다립니다.
        delay(5);
        // 0 ~ 253의 숫자를 입력하여 해당 아이디와 일치하는 모터의 현재전류값을 출력합니다.
       Serial.println(micro.getLimitCurrent(1));
       // 1초간 기다립니다.
       delay(1000);
    }
}

