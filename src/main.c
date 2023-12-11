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

// RED {255, 255, 0}
// GREEN {0, 255, 255}
// BLUE {255, 0, 255}
// BLACK {255, 255, 255}

int main(void)
{
    int doorOpened = 0;
    // wiringPi 초기화
    if (wiringPiSetupGpio() == -1) {
        fprintf(stderr, "wiringPi 초기화에 실패했습니다.\n");
        return 1;
    }
    // PN532 초기화 및 설정
    initializePn532();
    // 터치패드 초기화 및 설정
    touchInit();
    // NFC 카드 읽기
    // readNfcCard();
    // 비밀번호 인식
    char password[32];
    getPassword(password);
    printf("%s\n", password);
    return 0;
}