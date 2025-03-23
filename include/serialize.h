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


int serialize(const void *struct_ptr, uint8_t *buffer, size_t buffer_len);

#ifdef __cplusplus
}
#endif
#endif //PACKET_H
