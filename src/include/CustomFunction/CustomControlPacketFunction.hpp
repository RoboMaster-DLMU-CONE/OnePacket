#ifndef CUSTOMCONTROLPACKETFUNCTION_HPP
#define CUSTOMCONTROLPACKETFUNCTION_HPP
#include "OnePacketException.hpp"
#include "CustomFunction/DJICRC/DJICRC.h"

static uint8_t seq{};

void S_CustomControlPacketFunction(const void *packet, uint8_t *buffer, size_t buffer_len);

void DS_CustomControlPacketFunction(const uint8_t *buffer, void *packet);

#endif //CUSTOMCONTROLPACKETFUNCTION_HPP
