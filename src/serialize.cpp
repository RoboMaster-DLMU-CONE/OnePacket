#include "serialize.h"
#include "PacketBase.hpp"
#include "CustomFunction/CustomFunction.hpp"

int serialize(const void *struct_ptr, uint8_t *buffer, const size_t buffer_len) {
    const auto *base = static_cast<const PacketBase *>(struct_ptr);
    if (const auto func = S_functionMap[base->cmd]; func != nullptr) {
        return func(struct_ptr, buffer, buffer_len);
    }
    return 0;
}
