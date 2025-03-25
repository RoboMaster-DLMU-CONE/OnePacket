#ifndef DATALENGTH_HPP
#define DATALENGTH_HPP

#include <cstdint>
#include <unordered_map>
using DataLengthMap = std::unordered_map<uint16_t, uint8_t>;
extern DataLengthMap data_length_map;

#endif //DATALENGTH_HPP
