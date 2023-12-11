#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define SCL_PIN 2
#define SDO_PIN 3

#define PW_LEN 4

unsigned char readKeypad(void);
void touchInit(void);
void getPassword(char*);