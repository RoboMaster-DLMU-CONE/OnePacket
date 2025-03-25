#include "deserialize.h"

#include "include/PacketBase.hpp"
#include "CustomFunction/CustomFunction.hpp"
#include <stdexcept>

int deserialize(const uint8_t *buffer, void *struct_ptr) {
    auto target_struct = static_cast<PacketBase *>(struct_ptr);
    try {
        const auto func = custom_function_map[buffer[0]].second;
        try {
            func(buffer, struct_ptr);
        } catch (const OnePacketException &e) {
            return e.errorCode();
        }
    } catch (const std::out_of_range &) {
        return -5;
    }
    return 1;
}
