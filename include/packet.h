#ifndef PACKET_H
#define PACKET_H
#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __attribute__((packed)) {
    const uint16_t cmd = 0x0302;
    uint8_t data[30]{};
} CustomControlPacket;

int serialize(const void *struct_ptr, uint8_t *buffer, size_t buffer_len);

#ifdef __cplusplus
}
#endif
#endif //PACKET_H
