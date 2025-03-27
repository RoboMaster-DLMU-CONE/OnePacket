#ifndef DATALENGTH_HPP
#define DATALENGTH_HPP

#include <cstdint>

inline uint8_t getDataLength(const uint16_t cmd) {
    switch (cmd) {
        case 0x0101:
            return 1;
        case 0x0201:
            return 28;
        default: return 0;
    }
}

#endif //DATALENGTH_HPP
