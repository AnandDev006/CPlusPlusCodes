# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\CODE\Find Digits"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\Find Digits\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Find_Digits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Find_Digits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Find_Digits.dir/flags.make

CMakeFiles/Find_Digits.dir/main.cpp.obj: CMakeFiles/Find_Digits.dir/flags.make
CMakeFiles/Find_Digits.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\Find Digits\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Find_Digits.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Find_Digits.dir\main.cpp.obj -c "E:\CODE\Find Digits\main.cpp"

CMakeFiles/Find_Digits.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Find_Digits.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\Find Digits\main.cpp" > CMakeFiles\Find_Digits.dir\main.cpp.i

CMakeFiles/Find_Digits.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Find_Digits.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\Find Digits\main.cpp" -o CMakeFiles\Find_Digits.dir\main.cpp.s

CMakeFiles/Find_Digits.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Find_Digits.dir/main.cpp.obj.requires

CMakeFiles/Find_Digits.dir/main.cpp.obj.provides: CMakeFiles/Find_Digits.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Find_Digits.dir\build.make CMakeFiles/Find_Digits.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Find_Digits.dir/main.cpp.obj.provides

CMakeFiles/Find_Digits.dir/main.cpp.obj.provides.build: CMakeFiles/Find_Digits.dir/main.cpp.obj


# Object files for target Find_Digits
Find_Digits_OBJECTS = \
"CMakeFiles/Find_Digits.dir/main.cpp.obj"

# External object files for target Find_Digits
Find_Digits_EXTERNAL_OBJECTS =

Find_Digits.exe: CMakeFiles/Find_Digits.dir/main.cpp.obj
Find_Digits.exe: CMakeFiles/Find_Digits.dir/build.make
Find_Digits.exe: CMakeFiles/Find_Digits.dir/linklibs.rsp
Find_Digits.exe: CMakeFiles/Find_Digits.dir/objects1.rsp
Find_Digits.exe: CMakeFiles/Find_Digits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\Find Digits\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Find_Digits.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Find_Digits.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Find_Digits.dir/build: Find_Digits.exe

.PHONY : CMakeFiles/Find_Digits.dir/build

CMakeFiles/Find_Digits.dir/requires: CMakeFiles/Find_Digits.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Find_Digits.dir/requires

CMakeFiles/Find_Digits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Find_Digits.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Find_Digits.dir/clean

CMakeFiles/Find_Digits.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\Find Digits" "E:\CODE\Find Digits" "E:\CODE\Find Digits\cmake-build-debug" "E:\CODE\Find Digits\cmake-build-debug" "E:\CODE\Find Digits\cmake-build-debug\CMakeFiles\Find_Digits.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Find_Digits.dir/depend

