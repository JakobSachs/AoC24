// src/lib/utils.cc
#include "utils.h"
#include <cstring>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

namespace aoc24 {

std::ifstream open_input_file_for_day(const std::string &day_file) {
  const std::string day = std::filesystem::path(day_file).stem();
  const std::string input_path =
      std::string(AOC_ROOT_DIR) + "/inputs/" + day + ".txt";
  std::ifstream infile(input_path);
  if (!infile.is_open()) {
    std::cerr << "Failed to open " << input_path << std::endl;
  }
  return infile;
}

std::vector<std::string> read_lines(const std::string &day) {
  std::ifstream infile = open_input_file_for_day(day);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(infile, line)) {
    lines.push_back(line);
  }

  return lines;
}

std::string read_file(const std::string &day) {
  std::ifstream infile = open_input_file_for_day(day);
  std::ostringstream ss;
  ss << infile.rdbuf();
  return ss.str();
}

} // namespace aoc24
