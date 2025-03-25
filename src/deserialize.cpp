#include "deserialize.h"

#include "CustomFunction/CustomFunction.hpp"
#include <stdexcept>

#include "DataLength.hpp"

int deserialize(const uint8_t *buffer, void *struct_ptr) {
    try {
        const auto func = custom_function_map.at(buffer[0]).second;
        try {
            func(buffer, struct_ptr);
        } catch (const OnePacketException &e) {
            return e.errorCode();
        }
    } catch (const std::out_of_range &) {
        try {
            const uint16_t cmd = buffer[0] + (buffer[1] << 8);
            const auto dataLength = data_length_map.at(cmd);
            if (Verify_CRC8_Check_Sum(buffer, 3) == 0 || Verify_CRC16_Check_Sum(buffer, 4 + dataLength)) {
                return -2;
            }
            memcpy(static_cast<uint8_t *>(struct_ptr) + 2, buffer + 3, dataLength);
        } catch (const std::out_of_range &) {
            return -5;
        }
    }
    return 1;
}
