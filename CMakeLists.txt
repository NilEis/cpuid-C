cmake_minimum_required(VERSION 3.0.0)
project(CPUInfo VERSION 0.1.0)

add_subdirectory(cpuid)

add_executable(CPUInfo main.c)

target_compile_options(CPUInfo PRIVATE $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall -Wextra -pedantic -pedantic-errors> $<$<CXX_COMPILER_ID:MSVC>: /W4>)

include_directories(./cpuid)

target_link_libraries(CPUInfo cpuid)

