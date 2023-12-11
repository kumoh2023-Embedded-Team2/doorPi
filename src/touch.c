#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include "touch.h"
#include "rgb_led.h"

#define SCL_PIN 8
#define SDO_PIN 7

#define PW_LEN 4

void touchInit()
{
    pinMode(SCL_PIN, OUTPUT);
    pinMode(SDO_PIN, INPUT);
    printf("HW136 터치패드 초기화 완료\n");
}

void getPassword(char *password)
{
    wiringPiSetupGpio();
    unsigned char Key[PW_LEN];

    for(int i = 0; i < PW_LEN; i++){
        while (readKeypad() == 0x00);
        Key[i] = readKeypad();
        printf("%d\n", Key[i]);
        RGBled(255, 255, 0);
        delay(1000);
    }

    sprintf(password, "%02d%02d%02d%02d", Key[0], Key[1], Key[2], Key[3]);
    printf("%s\n", password);
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
