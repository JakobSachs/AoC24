#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include "utils.h"

const std::vector<std::string> test_lines = std::vector(
    {std::string("3   4"), std::string("4   3"), std::string("2   5"),
     std::string("1   3"), std::string("3   9"), std::string("3   3")});

std::pair<u32, u32> solve() {
  const std::vector<std::string> lines = aoc24::read_lines(__FILE_NAME__);
  // std::vector<std::string> lines = test_lines;

  std::vector<u32> left_ids, right_ids;
  left_ids.reserve(lines.size());
  right_ids.reserve(lines.size());

  // split each line on first space and parse left & right side to u32
  for (const auto &line : lines) {
    auto pos = line.find_first_of(" \t");
    u32 l_val = std::stoi(line.substr(0, pos));
    u32 r_val = std::stoi(line.substr(pos + 1));

    auto l_it = std::lower_bound(left_ids.begin(), left_ids.end(), l_val);
    left_ids.insert(l_it, l_val);

    auto r_it = std::lower_bound(right_ids.begin(), right_ids.end(), r_val);
    right_ids.insert(r_it, r_val);
  }

  std::vector<u32> distances;
  distances.reserve(lines.size());

  // calculate distances
  std::transform(left_ids.begin(), left_ids.end(), right_ids.begin(),
                 std::back_inserter(distances), [](const u32 a, const u32 b) {
                   // remember to cast to i32 for abs() to work
                   return std::abs((i32)a - (i32)b);
                 });

  // sum distances
  const u32 day01_sum = std::accumulate(distances.begin(), distances.end(), 0);

  // calculate similarity scores
  std::transform(left_ids.cbegin(), left_ids.cend(), left_ids.begin(),
                 [&right_ids](u32 id) {
                   // since right_ids is already sorted, we can make this nicely
                   // efficient
                   auto range =
                       std::equal_range(right_ids.begin(), right_ids.end(), id);
                   return std::distance(range.first, range.second) * id;
                 });

  const u32 day02_sum = std::accumulate(left_ids.begin(), left_ids.end(), 0);

  return std::make_pair(day01_sum, day02_sum);
}

AOC24_MAIN(__FILE_NAME__);
