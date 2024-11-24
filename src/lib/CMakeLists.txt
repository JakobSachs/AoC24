# src/lib/CMakeLists.txt
add_library(aoc24_utils utils.cc)

target_include_directories(aoc24_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

