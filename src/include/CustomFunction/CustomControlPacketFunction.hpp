#ifndef CUSTOMCONTROLPACKETFUNCTION_HPP
#define CUSTOMCONTROLPACKETFUNCTION_HPP

#include <cstddef>
#include "DJICRC/DJICRC.h"

extern uint8_t seq;

int S_CustomControlPacketFunction(const void *packet, uint8_t *buffer, size_t buffer_len);

int DS_CustomControlPacketFunction(const uint8_t *buffer, void *packet);

#endif //CUSTOMCONTROLPACKETFUNCTION_HPP
