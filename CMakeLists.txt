cmake_minimum_required(VERSION 3.10)

# Project name
project(Platformer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 and SDL2_image packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Source directories
set(SRC_DIR "src")
file(GLOB_RECURSE SRCS "${SRC_DIR}/*.cpp")

# Add executable
add_executable(game "Main.cpp" ${SRCS})

# Link SDL2 and SDL2_image libraries
target_link_libraries(game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
