# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/mono/my_works/monotone/monotone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mono/my_works/monotone/monotone/build

# Include any dependencies generated for this target.
include CMakeFiles/monotone.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/monotone.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/monotone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monotone.dir/flags.make

CMakeFiles/monotone.dir/main.c.o: CMakeFiles/monotone.dir/flags.make
CMakeFiles/monotone.dir/main.c.o: /home/mono/my_works/monotone/monotone/main.c
CMakeFiles/monotone.dir/main.c.o: CMakeFiles/monotone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mono/my_works/monotone/monotone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/monotone.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/monotone.dir/main.c.o -MF CMakeFiles/monotone.dir/main.c.o.d -o CMakeFiles/monotone.dir/main.c.o -c /home/mono/my_works/monotone/monotone/main.c

CMakeFiles/monotone.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/monotone.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mono/my_works/monotone/monotone/main.c > CMakeFiles/monotone.dir/main.c.i

CMakeFiles/monotone.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/monotone.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mono/my_works/monotone/monotone/main.c -o CMakeFiles/monotone.dir/main.c.s

# Object files for target monotone
monotone_OBJECTS = \
"CMakeFiles/monotone.dir/main.c.o"

# External object files for target monotone
monotone_EXTERNAL_OBJECTS =

monotone: CMakeFiles/monotone.dir/main.c.o
monotone: CMakeFiles/monotone.dir/build.make
monotone: /usr/lib/x86_64-linux-gnu/libSDL2.so
monotone: CMakeFiles/monotone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mono/my_works/monotone/monotone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable monotone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monotone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monotone.dir/build: monotone
.PHONY : CMakeFiles/monotone.dir/build

CMakeFiles/monotone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monotone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monotone.dir/clean

CMakeFiles/monotone.dir/depend:
	cd /home/mono/my_works/monotone/monotone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mono/my_works/monotone/monotone /home/mono/my_works/monotone/monotone /home/mono/my_works/monotone/monotone/build /home/mono/my_works/monotone/monotone/build /home/mono/my_works/monotone/monotone/build/CMakeFiles/monotone.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/monotone.dir/depend

