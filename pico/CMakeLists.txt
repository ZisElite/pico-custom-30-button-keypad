cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(kb_manager C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(kb_manager kb_manager.c)

pico_enable_stdio_usb(kb_manager 1)
pico_enable_stdio_uart(kb_manager 1)

pico_add_extra_outputs(kb_manager)

target_link_libraries(kb_manager pico_stdlib)