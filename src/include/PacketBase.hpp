#ifndef PACKETBASE_HPP
#define PACKETBASE_HPP
#include <cstdint>

struct PacketBase {
    uint16_t cmd{};
    uint8_t headerCRC8{};
    uint16_t data[10]{};
    uint16_t tailCRC16{};
};

#endif //PACKETBASE_HPP
