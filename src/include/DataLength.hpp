#ifndef DATALENGTH_HPP
#define DATALENGTH_HPP

#include <cstdint>
#include <unordered_map>
using DataLengthMap = std::unordered_map<uint16_t, uint8_t>;
static DataLengthMap data_length_map = {{0x0101, 1}};

#endif //DATALENGTH_HPP
