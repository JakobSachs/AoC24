// src/lib/utils.h
#ifndef AOC24_UTILS_H
#define AOC24_UTILS_H

#include <fstream>
#include <string>
#include <vector>

namespace aoc24 {
std::ifstream open_input_file_for_day(const std::string &day);
std::vector<std::string> read_lines(const std::string &day);
std::string read_file(const std::string &day);
} // namespace aoc24

#endif // AOC24_UTILS_H
