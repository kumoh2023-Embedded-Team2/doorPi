#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include "servo.h"

void servoInit()
{
    pinMode(SERVO_PIN, OUTPUT);
    softPwmCreate(SERVO_PIN, NEUTRAL_DEGREE, SERVO_RANGE);
}

void servoOpen()
{
    softPwmWrite(SERVO_PIN, MAX_DEGREE);
    // printf("열림 ㅅㄱ\n");
    delay(4000);

    softPwmWrite(SERVO_PIN, NEUTRAL_DEGREE);
    // printf("닫힘 ㅅㄱ\n");
    delay(1000);
}
