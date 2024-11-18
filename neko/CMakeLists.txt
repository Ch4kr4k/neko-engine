# neko/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Neko)

# Specify source files
file(GLOB_RECURSE NEKO_SOURCES src/neko/*.cpp)

# Create the shared library
# add_library(neko SHARED ${NEKO_SOURCES})
add_library(neko STATIC ${NEKO_SOURCES})

# Set output directory for the shared library
set_target_properties(neko PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app/lib
)

# Define the include directories
target_include_directories(neko PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/glm
)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

#target_compile_definitions(neko PUBLIC GLFW_INCLUDE_NONE)

# Link OpenGL and GLFW
find_package(OpenGL REQUIRED)
# Set the OpenGL preference to GLVND
set(OpenGL_GL_PREFERENCE "GLVND")
target_link_libraries(neko 
  PRIVATE glfw 
  PRIVATE OpenGL::GL
  PRIVATE glad
  PRIVATE imgui
)


# Install the library
install(TARGETS neko
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app/lib
)

# Add subdirectory
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/imgui)
