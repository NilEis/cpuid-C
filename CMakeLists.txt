cmake_minimum_required(VERSION 3.0.0)
project(CPUInfo VERSION 0.1.0)

add_subdirectory(cpuid)

add_executable(CPUInfo main.c)

include_directories(./cpuid)

target_link_libraries(CPUInfo cpuid)
