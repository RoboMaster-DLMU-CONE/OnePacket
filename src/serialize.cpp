#include <stdexcept>
#include "serialize.h"
#include "PacketBase.hpp"
#include "CustomFunction/CustomFunction.hpp"

int serialize(const void *struct_ptr, uint8_t *buffer, const size_t buffer_len) {
    const auto *base = static_cast<const PacketBase *>(struct_ptr);
    try {
        const auto func = custom_function_map[base->cmd].first;
        try {
            func(struct_ptr, buffer, buffer_len);
        } catch (const OnePacketException &e) {
            return e.errorCode();
        }
        // Can't find custom function, use default process
    } catch (const std::out_of_range &) {
        buffer[0] = base->cmd & 0xFF;
        buffer[1] = base->cmd >> 8;
        buffer[2] = base->dataLength;
        buffer[3] = Get_CRC8_Check_Sum(buffer, 3, CRC8_INIT);
        memcpy(&buffer[4], base->data, base->dataLength);
        buffer[4 + base->dataLength] = Get_CRC16_Check_Sum(buffer, 4 + base->dataLength, CRC16_INIT);

        return 1;
    }


    return 1;
}
