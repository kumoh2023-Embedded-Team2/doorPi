#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include "bt.h"
#include "servo.h"
#include "touch.h"
#include "rgb_led.h"
#include "mutex.h"

#define SCL_PIN 8
#define SDO_PIN 7

#define PW_LEN 4
#define TOUCH_NUM "13131313"

void touchInit()
{
    pinMode(SCL_PIN, OUTPUT);
    pinMode(SDO_PIN, INPUT);
    printf("HW136 터치패드 초기화 완료\n");
}

void *readNumPad(){
    wiringPiSetupGpio();
    initMyTone();
    printf("터치패드 인식 기다리는 중...\n");
    const char *expectedNum = TOUCH_NUM;

    while(1){
        char password[32];
        getPassword(password);
        printf("인식 번호: %s\n", password);
        compareNum(password, expectedNum);
        printf("터치패드 인식 기다리는 중...\n");
    }
}

void getPassword(char *password)
{
    wiringPiSetupGpio();
    unsigned char Key[PW_LEN];

    for(int i = 0; i < PW_LEN; i++){
        while (readKeypad() == 0x00);
        Key[i] = readKeypad();
        printf("%d", Key[i]);
        fflush(stdout);
        RGBled(255, 0, 255);
        delay(1000);
    }
    printf("\n");

    sprintf(password, "%02d%02d%02d%02d", Key[0], Key[1], Key[2], Key[3]);
    // printf("%s\n", password);
}

unsigned char readKeypad()
{
    unsigned char Count;
    unsigned char Key_State = 0;

    for (Count = 1; Count <= 16; Count++)
    {
        digitalWrite(SCL_PIN, LOW);

        if (!digitalRead(SDO_PIN))
            Key_State = Count;

        digitalWrite(SCL_PIN, HIGH);
    }

    return Key_State;
}

void compareNum(char* password, const char* expectedNum) {
    if (strcmp(password, expectedNum) == 0) {
        printf("올바른 번호를 감지했습니다.\n");
        pthread_mutex_lock(&mutex);
        RGBled(0, 255, 255);
        serialWrite(fd_serial, IN_CHAR);
        servoOpen();
        pthread_mutex_unlock(&mutex);
        delay(1000);
    } else {
        printf("올바르지 않은 번호를 감지했습니다.\n");
        RGBled(255, 255, 0);
        delay(1000);
    }
}