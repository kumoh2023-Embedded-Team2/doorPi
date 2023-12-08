#include <stdio.h>
#include <unistd.h>
#include <softPwm.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "rgb_led.h"

int main(void)
{
    wiringPiSetupGpio();
    RGBled();
    return 0;
}