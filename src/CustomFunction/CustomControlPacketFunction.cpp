#include "CustomFunction/CustomControlPacketFunction.hpp"
#include "packets/CustomControllerPacket.h"

void S_CustomControlPacketFunction(const void *packet, uint8_t *buffer, const size_t buffer_len) {
    if (buffer_len != CustomControllerPacketBufferLength)
        throw BufferRangeOverflow(
            "The CustomControllerPacketBufferLength is " + std::to_string(CustomControllerPacketBufferLength) +
            ", buffer_len is " + std::to_string(buffer_len));

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
};

void DS_CustomControlPacketFunction(const uint8_t *buffer, void *packet) {
    if (buffer[0] != 0XA5) {
        throw OnePacketException();
    }
    if (Get_CRC8_Check_Sum(buffer, 4, CRC8_INIT) != buffer[4] || Get_CRC16_Check_Sum(
            buffer, CustomControllerPacketBufferLength, CRC16_INIT) != buffer[38]) {
        throw CRCException("");
    }
    std::copy(&buffer[7], &buffer[7] + 30, static_cast<CustomControlPacket *>(packet)->data);
}
