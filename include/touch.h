#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define SCL_PIN 8
#define SDO_PIN 7

#define PW_LEN 4

unsigned char readKeypad(void);
void touchInit(void);
void getPassword(char*);