#include "CustomFunction/DJIReferee.hpp"
#include "CustomFunction/CustomFunction.hpp"

int DS_DJIRefereeFunction(const uint8_t *buffer, void *packet) {
    if (buffer[0] != 0XA5) {
        return -1;
    }
    const uint16_t cmd = buffer[5] + (buffer[6] << 8);
    return getDeserialCustomFunction(cmd)(buffer, packet);
}
