# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree

# Include any dependencies generated for this target.
include CMakeFiles/PList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PList.dir/flags.make

CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o: CMakeFiles/PList.dir/flags.make
CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o: /home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o   -c /home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c

CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.i"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c > CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.i

CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.s"
	/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c -o CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.s

# Object files for target PList
PList_OBJECTS = \
"CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o"

# External object files for target PList
PList_EXTERNAL_OBJECTS =

libPList.so: CMakeFiles/PList.dir/home/Lession/Tool_C/Tool_C/src/Algorithm/List/src/List.c.o
libPList.so: CMakeFiles/PList.dir/build.make
libPList.so: CMakeFiles/PList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libPList.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PList.dir/build: libPList.so

.PHONY : CMakeFiles/PList.dir/build

CMakeFiles/PList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PList.dir/clean

CMakeFiles/PList.dir/depend:
	cd /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree /home/Lession/Tool_C/Tool_C/src/Algorithm/RBTree/CMakeFiles/PList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PList.dir/depend

