// src/lib/utils.h
#pragma once

#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef __FILE_NAME__
#include <string.h>

#define __FILE_NAME__                                                          \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define AOC24_BENCHMARK_COUNT 10000
#define AOC24_MAIN(DAY)                                                        \
  int main() {                                                                 \
    do {                                                                       \
      auto start = std::chrono::high_resolution_clock::now();                  \
                                                                               \
      for (u16 i = 0; i < (AOC24_BENCHMARK_COUNT); i++)                        \
        solve();                                                               \
                                                                               \
      auto end = std::chrono::high_resolution_clock::now();                    \
      auto duration =                                                          \
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);   \
                                                                               \
      const auto res = solve();                                                \
      printf("= %s output: %d\t%d\n", (DAY), res.first, res.second);           \
                                                                               \
      std::cout << "== Execution Time: "                                       \
                << ((f32)duration.count() / (f32)(AOC24_BENCHMARK_COUNT)) /    \
                       1000000.0                                               \
                << " ms\n";                                                    \
    } while (0);                                                               \
  }

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
