#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "bt.h"
#include "btn.h"
#include "rgb_led.h"
#include "servo.h"

#define BTN_PIO 24

void btnInit(){
    pinMode(BTN_PIO, INPUT);
}

void* readBtn() {
    while(1) {
        int result = digitalRead(BTN_PIO);
        if (result) 
        {
            printf("Button: %d\n", result);
            RGBled(0, 255, 255);
            serialWrite(fd_serial, OUT_CHAR);
            servoOpen();
            delay(100);
        }
    }
}