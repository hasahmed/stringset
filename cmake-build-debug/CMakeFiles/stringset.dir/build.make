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
CMAKE_SOURCE_DIR = /Users/hasankatie/programming/cworkspace/hlib/stringset

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stringset.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stringset.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stringset.dir/flags.make

CMakeFiles/stringset.dir/main.c.o: CMakeFiles/stringset.dir/flags.make
CMakeFiles/stringset.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stringset.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stringset.dir/main.c.o   -c /Users/hasankatie/programming/cworkspace/hlib/stringset/main.c

CMakeFiles/stringset.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stringset.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hasankatie/programming/cworkspace/hlib/stringset/main.c > CMakeFiles/stringset.dir/main.c.i

CMakeFiles/stringset.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stringset.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hasankatie/programming/cworkspace/hlib/stringset/main.c -o CMakeFiles/stringset.dir/main.c.s

CMakeFiles/stringset.dir/main.c.o.requires:

.PHONY : CMakeFiles/stringset.dir/main.c.o.requires

CMakeFiles/stringset.dir/main.c.o.provides: CMakeFiles/stringset.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/stringset.dir/build.make CMakeFiles/stringset.dir/main.c.o.provides.build
.PHONY : CMakeFiles/stringset.dir/main.c.o.provides

CMakeFiles/stringset.dir/main.c.o.provides.build: CMakeFiles/stringset.dir/main.c.o


CMakeFiles/stringset.dir/stringset.c.o: CMakeFiles/stringset.dir/flags.make
CMakeFiles/stringset.dir/stringset.c.o: ../stringset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/stringset.dir/stringset.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stringset.dir/stringset.c.o   -c /Users/hasankatie/programming/cworkspace/hlib/stringset/stringset.c

CMakeFiles/stringset.dir/stringset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stringset.dir/stringset.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hasankatie/programming/cworkspace/hlib/stringset/stringset.c > CMakeFiles/stringset.dir/stringset.c.i

CMakeFiles/stringset.dir/stringset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stringset.dir/stringset.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hasankatie/programming/cworkspace/hlib/stringset/stringset.c -o CMakeFiles/stringset.dir/stringset.c.s

CMakeFiles/stringset.dir/stringset.c.o.requires:

.PHONY : CMakeFiles/stringset.dir/stringset.c.o.requires

CMakeFiles/stringset.dir/stringset.c.o.provides: CMakeFiles/stringset.dir/stringset.c.o.requires
	$(MAKE) -f CMakeFiles/stringset.dir/build.make CMakeFiles/stringset.dir/stringset.c.o.provides.build
.PHONY : CMakeFiles/stringset.dir/stringset.c.o.provides

CMakeFiles/stringset.dir/stringset.c.o.provides.build: CMakeFiles/stringset.dir/stringset.c.o


# Object files for target stringset
stringset_OBJECTS = \
"CMakeFiles/stringset.dir/main.c.o" \
"CMakeFiles/stringset.dir/stringset.c.o"

# External object files for target stringset
stringset_EXTERNAL_OBJECTS =

stringset: CMakeFiles/stringset.dir/main.c.o
stringset: CMakeFiles/stringset.dir/stringset.c.o
stringset: CMakeFiles/stringset.dir/build.make
stringset: CMakeFiles/stringset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable stringset"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stringset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stringset.dir/build: stringset

.PHONY : CMakeFiles/stringset.dir/build

CMakeFiles/stringset.dir/requires: CMakeFiles/stringset.dir/main.c.o.requires
CMakeFiles/stringset.dir/requires: CMakeFiles/stringset.dir/stringset.c.o.requires

.PHONY : CMakeFiles/stringset.dir/requires

CMakeFiles/stringset.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stringset.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stringset.dir/clean

CMakeFiles/stringset.dir/depend:
	cd /Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hasankatie/programming/cworkspace/hlib/stringset /Users/hasankatie/programming/cworkspace/hlib/stringset /Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug /Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug /Users/hasankatie/programming/cworkspace/hlib/stringset/cmake-build-debug/CMakeFiles/stringset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stringset.dir/depend

