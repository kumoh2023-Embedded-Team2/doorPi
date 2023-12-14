#include <stdio.h>
#include <stdlib.h>
#include <nfc/nfc.h>
#include <wiringPi.h>
#include <string.h>
#include "bt.h"
#include "servo.h"

#define NFC_UID "ac08796d"

// #define SDA_PIN 8  // GPIO 8 (Physical pin 24)
// #define SCL_PIN 9  // GPIO 9 (Physical pin 21)

void initializePn532(void);
void *readNfcCard();
void getCurrentUid(unsigned char*, char*);
void compareUid(char*, const char*);