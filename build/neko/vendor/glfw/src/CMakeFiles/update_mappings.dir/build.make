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

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/progress.make

neko/vendor/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/chakrak/ws/proj/src/cpp/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glfw/src && /home/chakrak/venv/lib/python3.13/site-packages/cmake/data/bin/cmake -P /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glfw/CMake/GenerateMappings.cmake mappings.h.in mappings.h

neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/codegen:
.PHONY : neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/codegen

update_mappings: neko/vendor/glfw/src/CMakeFiles/update_mappings
update_mappings: neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/build

neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/clean

neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/depend:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chakrak/ws/proj/src/cpp/game_engine /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glfw/src /home/chakrak/ws/proj/src/cpp/game_engine/build /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/src /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : neko/vendor/glfw/src/CMakeFiles/update_mappings.dir/depend

