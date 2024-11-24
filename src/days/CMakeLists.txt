# src/days/CMakeLists.txt
file(GLOB DAY_SOURCES day*.cc)

foreach(DAY_SOURCE ${DAY_SOURCES})
    get_filename_component(DAY_NAME ${DAY_SOURCE} NAME_WE)
    add_executable(${DAY_NAME} ${DAY_SOURCE})

    # link utilities
    target_link_libraries(${DAY_NAME} aoc24_utils)

    set_target_properties(${DAY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
endforeach()
