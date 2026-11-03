cmake_minimum_required(VERSION 3.16)
project(ecu_tool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(ecu_tool
    src/main.c
    src/serial.c
    src/kline.c
    src/live.c
    src/checksum.c
)

if (MSVC)
    target_compile_options(ecu_tool PRIVATE /W4)
else()
    target_compile_options(ecu_tool PRIVATE -Wall -Wextra -Wpedantic)
endif()

if (APPLE)
    find_library(IOKIT_FRAMEWORK IOKit)
    if (IOKIT_FRAMEWORK)
        target_link_libraries(ecu_tool PRIVATE ${IOKIT_FRAMEWORK})
    endif()
endif()
