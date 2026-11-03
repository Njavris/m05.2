cmake_minimum_required(VERSION 3.16)
project(ecu_diag C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(ecu_diag
    src/main.c
    ../ecu_tool/src/serial.c
    ../ecu_tool/src/kline.c
    ../ecu_tool/src/live.c
    ../ecu_tool/src/checksum.c
)

target_include_directories(ecu_diag PRIVATE
    src
    ../ecu_tool/src
)

if (MSVC)
    target_compile_options(ecu_diag PRIVATE /W4)
else()
    target_compile_options(ecu_diag PRIVATE -Wall -Wextra -Wpedantic)
endif()

if (APPLE)
    find_library(IOKIT_FRAMEWORK IOKit)
    if (IOKIT_FRAMEWORK)
        target_link_libraries(ecu_diag PRIVATE ${IOKIT_FRAMEWORK})
    endif()
endif()
