# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/Desktop/2048_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/Desktop/2048_practice/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2048_practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2048_practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2048_practice.dir/flags.make

CMakeFiles/2048_practice.dir/main.cpp.o: CMakeFiles/2048_practice.dir/flags.make
CMakeFiles/2048_practice.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/Desktop/2048_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2048_practice.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2048_practice.dir/main.cpp.o -c /Users/apple/Desktop/2048_practice/main.cpp

CMakeFiles/2048_practice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2048_practice.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/Desktop/2048_practice/main.cpp > CMakeFiles/2048_practice.dir/main.cpp.i

CMakeFiles/2048_practice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2048_practice.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/Desktop/2048_practice/main.cpp -o CMakeFiles/2048_practice.dir/main.cpp.s

CMakeFiles/2048_practice.dir/Playground2048.cpp.o: CMakeFiles/2048_practice.dir/flags.make
CMakeFiles/2048_practice.dir/Playground2048.cpp.o: ../Playground2048.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/Desktop/2048_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2048_practice.dir/Playground2048.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2048_practice.dir/Playground2048.cpp.o -c /Users/apple/Desktop/2048_practice/Playground2048.cpp

CMakeFiles/2048_practice.dir/Playground2048.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2048_practice.dir/Playground2048.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/Desktop/2048_practice/Playground2048.cpp > CMakeFiles/2048_practice.dir/Playground2048.cpp.i

CMakeFiles/2048_practice.dir/Playground2048.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2048_practice.dir/Playground2048.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/Desktop/2048_practice/Playground2048.cpp -o CMakeFiles/2048_practice.dir/Playground2048.cpp.s

# Object files for target 2048_practice
2048_practice_OBJECTS = \
"CMakeFiles/2048_practice.dir/main.cpp.o" \
"CMakeFiles/2048_practice.dir/Playground2048.cpp.o"

# External object files for target 2048_practice
2048_practice_EXTERNAL_OBJECTS =

2048_practice: CMakeFiles/2048_practice.dir/main.cpp.o
2048_practice: CMakeFiles/2048_practice.dir/Playground2048.cpp.o
2048_practice: CMakeFiles/2048_practice.dir/build.make
2048_practice: CMakeFiles/2048_practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/Desktop/2048_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 2048_practice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2048_practice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2048_practice.dir/build: 2048_practice

.PHONY : CMakeFiles/2048_practice.dir/build

CMakeFiles/2048_practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2048_practice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2048_practice.dir/clean

CMakeFiles/2048_practice.dir/depend:
	cd /Users/apple/Desktop/2048_practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/Desktop/2048_practice /Users/apple/Desktop/2048_practice /Users/apple/Desktop/2048_practice/cmake-build-debug /Users/apple/Desktop/2048_practice/cmake-build-debug /Users/apple/Desktop/2048_practice/cmake-build-debug/CMakeFiles/2048_practice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2048_practice.dir/depend
