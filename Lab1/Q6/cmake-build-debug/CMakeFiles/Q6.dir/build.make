# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Q6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Q6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q6.dir/flags.make

CMakeFiles/Q6.dir/main.c.obj: CMakeFiles/Q6.dir/flags.make
CMakeFiles/Q6.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Q6.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Q6.dir\main.c.obj   -c "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\main.c"

CMakeFiles/Q6.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Q6.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\main.c" > CMakeFiles\Q6.dir\main.c.i

CMakeFiles/Q6.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Q6.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\main.c" -o CMakeFiles\Q6.dir\main.c.s

# Object files for target Q6
Q6_OBJECTS = \
"CMakeFiles/Q6.dir/main.c.obj"

# External object files for target Q6
Q6_EXTERNAL_OBJECTS =

Q6.exe: CMakeFiles/Q6.dir/main.c.obj
Q6.exe: CMakeFiles/Q6.dir/build.make
Q6.exe: CMakeFiles/Q6.dir/linklibs.rsp
Q6.exe: CMakeFiles/Q6.dir/objects1.rsp
Q6.exe: CMakeFiles/Q6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Q6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Q6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q6.dir/build: Q6.exe

.PHONY : CMakeFiles/Q6.dir/build

CMakeFiles/Q6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Q6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Q6.dir/clean

CMakeFiles/Q6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6" "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6" "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug" "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug" "C:\Users\Ashpan\Drive\Current\School\Second Year\COMPENG 2SH4\Labs\Lab1\Q6\cmake-build-debug\CMakeFiles\Q6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Q6.dir/depend

