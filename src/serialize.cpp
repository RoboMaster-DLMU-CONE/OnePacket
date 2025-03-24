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
    } catch (const std::out_of_range &) {
    }


    return 1;
}
