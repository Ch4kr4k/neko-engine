# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/chakrak/venv/lib/python3.13/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/chakrak/venv/lib/python3.13/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chakrak/ws/proj/src/cpp/game_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chakrak/ws/proj/src/cpp/game_engine/build

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include neko/vendor/glfw/docs/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include neko/vendor/glfw/docs/CMakeFiles/docs.dir/progress.make

neko/vendor/glfw/docs/CMakeFiles/docs.dir/codegen:
.PHONY : neko/vendor/glfw/docs/CMakeFiles/docs.dir/codegen

docs: neko/vendor/glfw/docs/CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
neko/vendor/glfw/docs/CMakeFiles/docs.dir/build: docs
.PHONY : neko/vendor/glfw/docs/CMakeFiles/docs.dir/build

neko/vendor/glfw/docs/CMakeFiles/docs.dir/clean:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/docs && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : neko/vendor/glfw/docs/CMakeFiles/docs.dir/clean

neko/vendor/glfw/docs/CMakeFiles/docs.dir/depend:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chakrak/ws/proj/src/cpp/game_engine /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glfw/docs /home/chakrak/ws/proj/src/cpp/game_engine/build /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/docs /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/docs/CMakeFiles/docs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : neko/vendor/glfw/docs/CMakeFiles/docs.dir/depend

