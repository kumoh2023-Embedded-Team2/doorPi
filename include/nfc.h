#include <stdio.h>
#include <stdlib.h>
#include <nfc/nfc.h>
#include <wiringPi.h>
#include <string.h>

// #define SDA_PIN 8  // GPIO 8 (Physical pin 24)
// #define SCL_PIN 9  // GPIO 9 (Physical pin 21)

void initializePn532();
void readNfcCard();
void getCurrentUid(unsigned char*, char*);
void compareUid(char*, const char*);