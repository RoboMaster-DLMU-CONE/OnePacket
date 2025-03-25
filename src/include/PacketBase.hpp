#ifndef PACKETBASE_HPP
#define PACKETBASE_HPP
#include <cstdint>

struct __attribute__((packed)) PacketBase {
    uint16_t cmd{};
    uint8_t dataLength{};
    uint8_t headerCRC8{};
    uint8_t data[255]{};
    uint16_t tailCRC16{};
};

#endif //PACKETBASE_HPP
