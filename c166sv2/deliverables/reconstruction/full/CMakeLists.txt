cmake_minimum_required(VERSION 3.16)
project(mt05_full_reconstruction C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(mt05_catalog STATIC
    src/catalog.c
    src/catalog_data.c
    src/live_data.c
    src/live_data_data.c
)

target_include_directories(mt05_catalog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MSVC)
    target_compile_options(mt05_catalog PRIVATE /W4)
else()
    target_compile_options(mt05_catalog PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(mt05_catalog_test tests/test_catalog.c)
target_link_libraries(mt05_catalog_test PRIVATE mt05_catalog)

enable_testing()
add_test(NAME catalog COMMAND mt05_catalog_test)
