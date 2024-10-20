# glad/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(glad_library)

# Set position-independent code for shared libraries
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Create the static library
add_library(glad STATIC src/glad.c)

# Include directories
target_include_directories(glad PUBLIC include)

# Set library properties (optional)
set_target_properties(glad PROPERTIES
    OUTPUT_NAME "glad"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
