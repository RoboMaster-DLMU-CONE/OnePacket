#ifndef DESERIALIZE_H
#define DESERIALIZE_H

#ifdef __cplusplus
#include <cstdint>
#include <cstddef>
#else
#include <stdint.h>
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


int deserialize(const uint8_t *buffer, void *struct_ptr);

#ifdef __cplusplus
}
#endif

#endif //DESERIALIZE_H
