#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "bt.h"
#include "btn.h"
#include "rgb_led.h"
#include "servo.h"
#include "mutex.h"

#define BTN_PIO 24

void btnInit(){
    pinMode(BTN_PIO, INPUT);
}

void* readBtn() {
    while(1) {
        int result = digitalRead(BTN_PIO);
        if (result) 
        {
            printf("버튼 입력을 감지했습니다. status: %d\n", result);
            pthread_mutex_lock(&mutex);
            RGBled(0, 255, 255);
            serialWrite(fd_serial, OUT_CHAR);
            servoOpen();
            pthread_mutex_unlock(&mutex);
            delay(100);
        }
    }
}