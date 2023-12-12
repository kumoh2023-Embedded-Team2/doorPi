// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <softPwm.h>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>
// #include <nfc/nfc.h>
#include "rgb_led.h"
#include "nfc.h"
#include "touch.h"
#include "bt.h"
#include <pthread.h>

// RED {255, 255, 0}
// GREEN {0, 255, 255}
// BLUE {255, 0, 255}
// BLACK {255, 255, 255}

int main(void)
{
    // wiringPi 초기화
    
    if (wiringPiSetupGpio() == -1) {
        fprintf(stderr, "wiringPi 초기화에 실패했습니다.\n");
        return 1;
    }

    // PN532 초기화 및 설정
    initializePn532();
    // 터치패드 초기화 및 설정
    touchInit();
    // 블루투스 초기화 및 설정
    btInit();

    pthread_t ptNfc;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&ptNfc, NULL, readNfcCard, NULL);
    pthread_join(ptNfc, NULL);
    pthread_mutex_destroy(&mutex);
    
    // NFC 카드 읽기
    //readNfcCard();
    // 비밀번호 인식
    //readNumPad();


    return 0;
}

// TODO: mutex로 readNfcCard, readNumPad 연결 필요
// TODO: 버튼, 서보모터, 부저 모듈 추가 필요 