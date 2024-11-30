// src/lib/utils.h
#ifndef AOC24_UTILS_H
#define AOC24_UTILS_H

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

namespace aoc24 {
std::ifstream open_input_file_for_day(const std::string &day);
std::vector<std::string> read_lines(const std::string &day);
std::string read_file(const std::string &day);
} // namespace aoc24

#endif // AOC24_UTILS_H
