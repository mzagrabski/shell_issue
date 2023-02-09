cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(shell_issue)

target_sources(app PRIVATE src/main.c)

add_subdirectory(src/lib_cmd1)
add_subdirectory(src/lib_cmd2)
