cmake_minimum_required(VERSION 3.16)

project(SentinelGuard
    VERSION 0.1.0
    DESCRIPTION "Lightweight C++ system monitoring and automation sentinel"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(sentinel_guard ${SOURCES})

# Warnings (important for portfolio quality)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(sentinel_guard PRIVATE -Wall -Wextra -Wpedantic)
endif()
