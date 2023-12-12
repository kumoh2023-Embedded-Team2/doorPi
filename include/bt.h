#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define BAUD_RATE 115200 //블루투스의 보율이 바뀔 경우 이 값을 변경해야함 

extern int fd_serial;

void serialWrite(const int fd, const unsigned char c);
int btInit(void);  