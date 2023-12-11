#include <stdio.h>
#include <stdlib.h>
#include <nfc/nfc.h>
#include <wiringPi.h>
#include <string.h>
#include "nfc.h"
#include "rgb_led.h"

#define SDA_PIN 8  // GPIO 8 (Physical pin 24)
#define SCL_PIN 9  // GPIO 9 (Physical pin 21)

// PN532 초기화 함수
void initializePn532() {
    nfc_context *context;
    nfc_device *pnd;

    // libnfc 초기화 및 리더기 설정
    nfc_init(&context);
    if (context == NULL) {
        fprintf(stderr, "libnfc 초기화에 실패했습니다. (malloc)\n");
        exit(EXIT_FAILURE);
    }

    // 첫 번째로 발견된 NFC 장치 열기
    pnd = nfc_open(context, NULL);
    if (pnd == NULL) {
        fprintf(stderr, "NFC 장치 열기에 실패했습니다.\n");
        nfc_exit(context);
        exit(EXIT_FAILURE);
    }

    // PN532를 위한 SDA 및 SCL 핀 설정
    nfc_device_set_property_int(pnd, NP_HANDLE_CRC, 1);
    nfc_device_set_property_int(pnd, NP_HANDLE_PARITY, 0);
    nfc_device_set_property_int(pnd, NP_HANDLE_PARITY, 7);  // NP_HANDLE_BITS 대신 NP_HANDLE_PARITY 사용
    nfc_device_set_property_int(pnd, NP_ACTIVATE_FIELD, 1);

    printf("PN532 NFC 리더기 초기화 완료\n");
}

// NFC 카드 읽기 함수
void readNfcCard() {
    nfc_target nt;
    nfc_context *context;
    nfc_device *pnd;
    nfc_modulation modulation;

    // libnfc 초기화 및 리더기 설정
    nfc_init(&context);
    if (context == NULL) {
        fprintf(stderr, "libnfc 초기화에 실패했습니다. (malloc)\n");
        exit(EXIT_FAILURE);
    }

    // 첫 번째로 발견된 NFC 장치 열기
    pnd = nfc_open(context, NULL);
    if (pnd == NULL) {
        fprintf(stderr, "NFC 장치 열기에 실패했습니다.\n");
        nfc_exit(context);
        exit(EXIT_FAILURE);
    }

    // NFC 타겟 대기
    printf("NFC 카드를 기다리는 중...\n");

    // Mifare 카드의 경우 NMT_ISO14443A 사용
    modulation.nmt = NMT_ISO14443A;
    modulation.nbr = NBR_106;

    const char *expectedUID = "ac08796d";  // 여기에 실제 UID를 넣어주세요

    // NFC 타겟 선택
    while (true) {
        if (nfc_initiator_select_passive_target(pnd, modulation, NULL, 0, &nt) > 0) {
          char currentUID[32];  // 충분한 크기로 지정
          getCurrentUid(nt.nti.nai.abtUid, currentUID);
          // 카드 UID 출력
          printf("카드 UID: %s\n", currentUID);
          
          compareUid(currentUID, expectedUID);
        }
        else printf("NFC 카드를 기다리는 중...\n");
        delay(1000);
    }

    // NFC 장치 닫기
    nfc_close(pnd);
    nfc_exit(context);
}

void getCurrentUid(unsigned char* abtUid, char* currentUID) {
  sprintf(currentUID, "%02x%02x%02x%02x", abtUid[0], abtUid[1], abtUid[2], abtUid[3]);
}

void compareUid(char* currentUID, const char* expectedUID) {
  if (strcmp(currentUID, expectedUID) == 0) {
    printf("올바른 카드를 감지했습니다.\n");
    RGBled(0, 255, 255);
  } else {
    printf("올바르지 않은 카드를 감지했습니다.\n");
    RGBled(255, 255, 0);
  }
}