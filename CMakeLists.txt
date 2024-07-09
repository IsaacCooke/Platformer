cmake_minimum_required(VERSION 3.10)

# Project name
project(Platformer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include raylib
include_directories(/usr/include/raylib)

# Linker flags
link_libraries(raylib m pthread dl rt X11)

# Source directories
set(SRC_DIR "src")
file(GLOB_RECURSE SRCS "${SRC_DIR}/*.cpp")

# Add executable
add_executable(game main.cpp ${SRCS})
