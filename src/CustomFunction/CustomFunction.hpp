#ifndef CUSTOMFUNCTION_HPP
#define CUSTOMFUNCTION_HPP
#include <cstdint>
#include <unordered_map>
#include "CustomControlPacketFunction.hpp"

using std::pair;
using S_CustomFunc = void(*)(const void *, uint8_t *, const size_t);
using DS_CustomFunc = void(*)(const uint8_t *, void *);
using CustomFunctionMap = std::unordered_map<uint16_t, pair<S_CustomFunc, DS_CustomFunc> >;


static CustomFunctionMap custom_function_map = {
    {0x0302, {S_CustomControlPacketFunction, DS_CustomControlPacketFunction}}
};
#endif //CUSTOMFUNCTION_HPP
