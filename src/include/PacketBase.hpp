#ifndef PACKETBASE_HPP
#define PACKETBASE_HPP
#include <cstdint>

struct __attribute__((packed)) PacketBase {
    //Header Part
    uint16_t cmd{};
    //End of Header (CRC8)
    //Data Part
    uint8_t data[255]{};
    //End of Data
    //Full Packet Verify (CRC16)
};

#endif //PACKETBASE_HPP
