#include "CustomFunction/DJIReferee.hpp"
#include "OnePacketException.hpp"
#include "CustomFunction/CustomFunction.hpp"
#include <stdexcept>

void DS_DJIRefereeFunction(const uint8_t *buffer, void *packet) {
    if (buffer[0] != 0XA5) {
        throw OnePacketException();
    }
    const uint16_t cmd = buffer[5] + (buffer[6] << 8);
    custom_function_map.at(cmd).second(buffer, packet);
}
