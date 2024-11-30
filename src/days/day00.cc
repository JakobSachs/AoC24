// src/days/day00.cc
#include "utils.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <iterator>
#include <vector>

const char digits[][9] = {"one", "two",   "three", "four", "five",
                          "six", "seven", "eight", "nine"};

int main() {
  const std::vector<std::string> lines = aoc24::read_lines(__FILE_NAME__);

  u32 d1_sum = 0;
  u32 d2_sum = 0;

  for (const auto &line : lines) { // simple part 1
    // auto fr = line.find_first_of("01234567890");
    const auto fr = std::find_if(line.begin(), line.end(),
                                 [](char c) { return std::isdigit(c); });

    const auto lr = std::find_if(line.rbegin(), line.rend(),
                                 [](char c) { return std::isdigit(c); });

    d1_sum += (*fr - '0') * 10 + (*lr - '0');

    // index and value of first 'number'
    size_t fi = std::distance(line.begin(), fr);
    u8 fv = *fr - '0';

    // - || - last 'number'
    size_t li = std::distance(line.begin(), lr.base() - 1);
    u8 lv = *lr - '0';

    for (u8 i = 0; i < 9; i++) { // see if we find a digit
      const char *d = digits[i];
      const size_t dfi = line.find(d);
      const size_t dli = line.rfind(d);

      if (dfi != line.npos && dfi < fi) {
        fi = dfi;
        fv = i + 1;
      }

      if (dli != line.npos && dli > li) {
        li = dli;
        lv = i + 1;
      }
    }

    d2_sum += fv * 10 + lv;
  }

  printf("Day 01 output: %d\t%d\n", d1_sum, d2_sum);

  return 0;
}
