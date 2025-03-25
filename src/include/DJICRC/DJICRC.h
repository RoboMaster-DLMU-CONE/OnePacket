#ifndef DJICRC_H
#define DJICRC_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TRUE 1
#define FALSE 0

const uint8_t CRC8_INIT = 0xff;
const uint16_t CRC16_INIT = 0xffff;

// CRC8
void Append_CRC8_Check_Sum(uint8_t *pchMessage, uint16_t dwLength);

uint32_t Verify_CRC8_Check_Sum(const uint8_t *pchMessage, uint16_t dwLength);

uint8_t Get_CRC8_Check_Sum(const uint8_t *pchMessage, uint16_t dwLength, uint8_t ucCRC8);

// CRC16
void Append_CRC16_Check_Sum(uint8_t *pchMessage, uint32_t dwLength);

uint32_t Verify_CRC16_Check_Sum(const uint8_t *pchMessage, uint32_t dwLength);

uint16_t Get_CRC16_Check_Sum(const uint8_t *pchMessage, uint32_t dwLength, uint16_t wCRC);

#ifdef __cplusplus
}
#endif

#endif //DJICRC_H
