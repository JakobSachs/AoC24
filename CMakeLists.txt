cmake_minimum_required(VERSION 3.20)
project(Aoc24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed,-lprofiler,--as-needed -g")


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type: Debug, Release" FORCE)
endif()

# compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()


add_compile_definitions(AOC_ROOT_DIR="${CMAKE_SOURCE_DIR}")


# Add subdirectories
add_subdirectory(src/lib)
add_subdirectory(src/days)
