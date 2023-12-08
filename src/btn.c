#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "btn.h"

#define BTN_PIO 24

void btnSet(){
    pinMode(BTN_PIO, INPUT);
}
