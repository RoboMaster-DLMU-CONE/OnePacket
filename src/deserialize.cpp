#include "deserialize.h"

#include "CustomFunction/CustomFunction.hpp"
#include <stdexcept>
#include <cstring>

#include "DataLength.hpp"

int deserialize(const uint8_t *buffer, void *struct_ptr) {
    const uint16_t cmd = buffer[0] + (buffer[1] << 8);
    const auto func = getDeserialCustomFunction(cmd);
    if (func) return func(buffer, struct_ptr);

    const auto data_length = getDataLength(cmd);
    if (data_length == 0) return PacketLengthNotDefined;
    if (Verify_CRC8_Check_Sum(buffer, 3) == 0 || Verify_CRC16_Check_Sum(buffer, 4 + data_length)) {
        return CRCError;
    }
    memcpy(static_cast<uint8_t *>(struct_ptr) + 2, buffer + 3, data_length);
    return 1;
}
