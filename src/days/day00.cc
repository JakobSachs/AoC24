// src/days/day00.cc
#include "utils.h"

int main() {
  const auto lines = aoc24::read_lines(__FILE_NAME__);

  for (const auto &line : lines) {
    printf("%s\n", line.c_str());
  }

  return 0;
}
