#ifndef CUSTOMFUNCTION_HPP
#define CUSTOMFUNCTION_HPP
#include <cstdint>
#include <unordered_map>
#include "CustomControlPacketFunction.hpp"

using S_CustomFunc = int(*)(const void *, uint8_t *, const size_t);
using S_FunctionMap = std::unordered_map<uint16_t, S_CustomFunc>;


static S_FunctionMap S_functionMap = {
    {0x0302, CustomControlPacketFunction}
};
#endif //CUSTOMFUNCTION_HPP
