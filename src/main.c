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

// #define RED {255, 255, 0}
// #define GREEN {0, 255, 255}
// #define BLUE {255, 0, 255}
// #define BLACK {255, 255, 255}

int main(void)
{
    // wiringPi 초기화
    if (wiringPiSetupGpio() == -1) {
        fprintf(stderr, "wiringPi 초기화에 실패했습니다.\n");
        return 1;
    }
    // PN532 초기화 및 설정
    initializePn532();
    // NFC 카드 읽기
    readNfcCard();
    return 0;
}