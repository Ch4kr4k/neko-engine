# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chakrak/ws/proj/src/cpp/game_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chakrak/ws/proj/src/cpp/game_engine/build

# Include any dependencies generated for this target.
include neko/vendor/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include neko/vendor/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include neko/vendor/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include neko/vendor/glad/CMakeFiles/glad.dir/flags.make

neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o: neko/vendor/glad/CMakeFiles/glad.dir/flags.make
neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o: /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glad/src/glad.c
neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o: neko/vendor/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chakrak/ws/proj/src/cpp/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o -MF CMakeFiles/glad.dir/src/glad.c.o.d -o CMakeFiles/glad.dir/src/glad.c.o -c /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glad/src/glad.c

neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glad/src/glad.c > CMakeFiles/glad.dir/src/glad.c.i

neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glad/src/glad.c -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

lib/libglad.a: neko/vendor/glad/CMakeFiles/glad.dir/src/glad.c.o
lib/libglad.a: neko/vendor/glad/CMakeFiles/glad.dir/build.make
lib/libglad.a: neko/vendor/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/chakrak/ws/proj/src/cpp/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../lib/libglad.a"
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
neko/vendor/glad/CMakeFiles/glad.dir/build: lib/libglad.a
.PHONY : neko/vendor/glad/CMakeFiles/glad.dir/build

neko/vendor/glad/CMakeFiles/glad.dir/clean:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : neko/vendor/glad/CMakeFiles/glad.dir/clean

neko/vendor/glad/CMakeFiles/glad.dir/depend:
	cd /home/chakrak/ws/proj/src/cpp/game_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chakrak/ws/proj/src/cpp/game_engine /home/chakrak/ws/proj/src/cpp/game_engine/neko/vendor/glad /home/chakrak/ws/proj/src/cpp/game_engine/build /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad /home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : neko/vendor/glad/CMakeFiles/glad.dir/depend

