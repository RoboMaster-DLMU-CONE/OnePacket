#include <stdexcept>
#include "serialize.h"

#include "DataLength.hpp"
#include "PacketBase.hpp"
#include "CustomFunction/CustomFunction.hpp"
#include <cstring>
int serialize(const void *struct_ptr, uint8_t *buffer, const size_t buffer_len) {
    const auto *base = static_cast<const PacketBase *>(struct_ptr);
    try {
        const auto func = custom_function_map.at(base->cmd).first;
        try {
            func(struct_ptr, buffer, buffer_len);
        } catch (const OnePacketException &e) {
            return e.errorCode();
        }
        // Can't find custom function, use default process
    } catch (const std::out_of_range &) {
        try {
            const auto data_length = data_length_map.at(base->cmd);
            buffer[0] = base->cmd & 0xFF;
            buffer[1] = base->cmd >> 8;
            buffer[2] = Get_CRC8_Check_Sum(buffer, 3, CRC8_INIT);
            memcpy(&buffer[3], base->data, data_length);
            buffer[3 + data_length] = Get_CRC16_Check_Sum(buffer, 4 + data_length, CRC16_INIT);
        } catch (const std::out_of_range &) {
            return -5;
        }
        return 1;
    }


    return 1;
}
