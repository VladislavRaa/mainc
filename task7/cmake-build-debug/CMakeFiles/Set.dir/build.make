# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Raa/CLionProjects/Set

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Raa/CLionProjects/Set/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Set.dir/flags.make

CMakeFiles/Set.dir/main.cpp.o: CMakeFiles/Set.dir/flags.make
CMakeFiles/Set.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Raa/CLionProjects/Set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Set.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Set.dir/main.cpp.o -c /Users/Raa/CLionProjects/Set/main.cpp

CMakeFiles/Set.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Set.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Raa/CLionProjects/Set/main.cpp > CMakeFiles/Set.dir/main.cpp.i

CMakeFiles/Set.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Set.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Raa/CLionProjects/Set/main.cpp -o CMakeFiles/Set.dir/main.cpp.s

CMakeFiles/Set.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Set.dir/main.cpp.o.requires

CMakeFiles/Set.dir/main.cpp.o.provides: CMakeFiles/Set.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Set.dir/build.make CMakeFiles/Set.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Set.dir/main.cpp.o.provides

CMakeFiles/Set.dir/main.cpp.o.provides.build: CMakeFiles/Set.dir/main.cpp.o


# Object files for target Set
Set_OBJECTS = \
"CMakeFiles/Set.dir/main.cpp.o"

# External object files for target Set
Set_EXTERNAL_OBJECTS =

Set: CMakeFiles/Set.dir/main.cpp.o
Set: CMakeFiles/Set.dir/build.make
Set: CMakeFiles/Set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Raa/CLionProjects/Set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Set"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Set.dir/build: Set

.PHONY : CMakeFiles/Set.dir/build

CMakeFiles/Set.dir/requires: CMakeFiles/Set.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Set.dir/requires

CMakeFiles/Set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Set.dir/clean

CMakeFiles/Set.dir/depend:
	cd /Users/Raa/CLionProjects/Set/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Raa/CLionProjects/Set /Users/Raa/CLionProjects/Set /Users/Raa/CLionProjects/Set/cmake-build-debug /Users/Raa/CLionProjects/Set/cmake-build-debug /Users/Raa/CLionProjects/Set/cmake-build-debug/CMakeFiles/Set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Set.dir/depend

