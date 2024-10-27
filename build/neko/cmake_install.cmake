# Install script for directory: /home/chakrak/ws/proj/src/cpp/game_engine/neko

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib" TYPE SHARED_LIBRARY FILES "/home/chakrak/ws/proj/src/cpp/game_engine/build/Out/app/lib/libneko.so")
  if(EXISTS "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/chakrak/ws/proj/src/cpp/game_engine/neko/../build/Out/app/lib/libneko.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/chakrak/ws/proj/src/cpp/game_engine/build/neko/CMakeFiles/neko.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glfw/cmake_install.cmake")
  include("/home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glad/cmake_install.cmake")
  include("/home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/imgui/cmake_install.cmake")
  include("/home/chakrak/ws/proj/src/cpp/game_engine/build/neko/vendor/glm/cmake_install.cmake")

endif()
