#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h> /* atoi( ) */

#define SERVO_PIN 19

#define MAX_DEGREE 120
#define NEUTRAL_DEGREE 75
#define MIN_DEGREE 30

void servoInit(void);

void servoOpen(void);