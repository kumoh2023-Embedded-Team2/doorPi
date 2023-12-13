#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h> /* atoi( ) */

#define SPK_PWM 18

void initMyTone()
{
    int duty = 0;
    int range = 200;
    int divisor = 96;

    pinMode(SPK_PWM, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(range);
    pwmSetClock(divisor);
    pwmWrite(SPK_PWM, duty);
}

void myTone(int freq)
{
    int duty = 50;
    int divisor = 96000 / freq;
    pwmSetClock(divisor);
    pwmWrite(SPK_PWM, duty);
}