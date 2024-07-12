cmake_minimum_required(VERSION 3.10)

# Project name
project(Platformer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include SDL2
include_directories(/usr/include/sdl2)

# Linker flags
link_libraries(SDL2)

# Source directories
set(SRC_DIR "src")
file(GLOB_RECURSE SRCS "${SRC_DIR}/*.cpp")

# Add executable
add_executable(game Main.cpp ${SRCS})
