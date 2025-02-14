# glad/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(stb_image)

# Set position-independent code for shared libraries
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Create the static library
add_library(stb_image STATIC stb_image.cpp)

# Include directories
target_include_directories(stb_image PUBLIC ./)

# Set library properties (optional)
set_target_properties(glad PROPERTIES
    OUTPUT_NAME "stb_image"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
