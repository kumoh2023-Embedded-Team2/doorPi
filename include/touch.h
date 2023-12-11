#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define SCL_PIN 8
#define SDO_PIN 7

#define PW_LEN 4

void touchInit(void);
void reedNumPad(void);
void getPassword(char*);
unsigned char readKeypad(void);
void compareNum(char*, const char*);