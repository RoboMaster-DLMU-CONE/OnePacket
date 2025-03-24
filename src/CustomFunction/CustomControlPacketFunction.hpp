#ifndef CUSTOMCONTROLPACKETFUNCTION_HPP
#define CUSTOMCONTROLPACKETFUNCTION_HPP
#include "packets/CustomControllerPacket.h"
#include "DJICRC/DJICRC.h"

uint8_t seq{};

int S_CustomControlPacketFunction(const void *packet, uint8_t *buffer, const size_t buffer_len) {
    if (buffer_len != CustomControllerPacketBufferLength) return -1;

    const auto controller_packet = static_cast<const CustomControlPacket *>(packet);
    seq = seq > 255 ? 0 : seq + 1;
    buffer[0] = 0xA5;
    buffer[1] = CustomControllerPacketBufferLength;
    buffer[2] = 0;
    buffer[3] = seq;
    buffer[4] = Get_CRC8_Check_Sum(controller_packet->data, 4, CRC8_INIT);
    buffer[5] = 0x02;
    buffer[6] = 0x03;
    memcpy(&buffer[7], controller_packet->data, 30);
    Append_CRC16_Check_Sum(buffer, CustomControllerPacketBufferLength);

    return 1;
};


#endif //CUSTOMCONTROLPACKETFUNCTION_HPP
