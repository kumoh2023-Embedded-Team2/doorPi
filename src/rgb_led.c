#include <stdio.h>
#include <unistd.h>
#include <softPwm.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "rgb_led.h"
#include "speaker.h"

#define UC unsigned char

#define R_PIO 11
#define G_PIO 9
#define B_PIO 10

void ledInit()
{
    softPwmCreate(R_PIO, 0, 255);
    softPwmCreate(G_PIO, 0, 255);
    softPwmCreate(B_PIO, 0, 255);
}

void ledColorSet(UC R_no, UC G_no, UC B_no)
{
    softPwmWrite(R_PIO, R_no);
    softPwmWrite(G_PIO, G_no);
    softPwmWrite(B_PIO, B_no);
}

void RGBled(UC R_no, UC G_no, UC B_no)
{
    pinMode(R_PIO, OUTPUT);
    pinMode(G_PIO, OUTPUT);
    pinMode(B_PIO, OUTPUT);
    ledInit();
    // int cont = 1;
    // UC R_no, G_no, B_no;
    // while (cont)
    // {
        // printf("R, G, B : ");
        // scanf("%hhu %hhu %hhu", &R_no, &G_no, &B_no);
    // printf("R: %u, G: %u, B: %u\n", R_no, G_no, B_no);
    ledColorSet(R_no, G_no, B_no);
    //     if (R_no + G_no + B_no == 0)
    //         cont = 0;
    // }
    myTone(262);
    delay(1000);
    initMyTone();
    ledColorSet(255, 255, 255);
}
