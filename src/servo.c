#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "servo.h"

void servoInit()
{
    int range = 1000;
    int divisor = 384;

    pinMode(SERVO_PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(range);
    pwmSetClock(divisor);
    
    pwmWrite(SERVO_PIN, NEUTRAL_DEGREE);
}

void servoOpen()
{
    pwmWrite(SERVO_PIN, MAX_DEGREE);
    printf("열림 ㅅㄱ\n");
    delay(5000);
    pwmWrite(SERVO_PIN, NEUTRAL_DEGREE);
    printf("닫힘 ㅅㄱ\n");
}