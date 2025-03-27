#ifndef CUSTOMFUNCTION_HPP
#define CUSTOMFUNCTION_HPP

#include <cstdint>
#include <unordered_map>
#include "CustomControlPacketFunction.hpp"
#include "DJIReferee.hpp"
#include "../../error.h"

using std::pair;
using S_CustomFunc = int(*)(const void *, uint8_t *, const size_t);
using DS_CustomFunc = int(*)(const uint8_t *, void *);
using CustomFunctionMap = std::unordered_map<uint16_t, pair<S_CustomFunc, DS_CustomFunc> >;

inline int NullSCustomFunc(const void *, uint8_t *, const size_t) {
    return UnknownError;
};

inline int (*getSerialCustomFunction(const uint16_t cmd))(const void *, uint8_t *, const size_t) {
    switch (cmd) {
        case 0xA5:
            return NullSCustomFunc;
        case 0x0302:
            return S_CustomControlPacketFunction;
        default:
            return nullptr;
    }
}

inline int (*getDeserialCustomFunction(const uint16_t cmd))(const uint8_t *, void *) {
    switch (cmd) {
        case 0xA5:
            return DS_DJIRefereeFunction;
        case 0x0302:
            return DS_CustomControlPacketFunction;
        default:
            return nullptr;
    }
}
#endif //CUSTOMFUNCTION_HPP
