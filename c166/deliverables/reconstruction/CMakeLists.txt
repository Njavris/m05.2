cmake_minimum_required(VERSION 3.16)
project(mt05_curated_reconstruction C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(mt05_curated_data STATIC 03-data/data.c)
target_include_directories(mt05_curated_data PUBLIC 03-data)
if (MSVC)
    target_compile_options(mt05_curated_data PRIVATE /W4)
else()
    target_compile_options(mt05_curated_data PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_test(NAME curated_compile COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target mt05_curated_data)
