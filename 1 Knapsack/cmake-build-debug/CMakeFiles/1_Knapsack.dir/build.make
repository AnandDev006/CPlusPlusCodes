# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\Users\HawK\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\HawK\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.3727.114\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/1_Knapsack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_Knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_Knapsack.dir/flags.make

CMakeFiles/1_Knapsack.dir/main.cpp.obj: CMakeFiles/1_Knapsack.dir/flags.make
CMakeFiles/1_Knapsack.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_Knapsack.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\1_Knapsack.dir\main.cpp.obj -c "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\main.cpp"

CMakeFiles/1_Knapsack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_Knapsack.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\main.cpp" > CMakeFiles\1_Knapsack.dir\main.cpp.i

CMakeFiles/1_Knapsack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_Knapsack.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\main.cpp" -o CMakeFiles\1_Knapsack.dir\main.cpp.s

CMakeFiles/1_Knapsack.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/1_Knapsack.dir/main.cpp.obj.requires

CMakeFiles/1_Knapsack.dir/main.cpp.obj.provides: CMakeFiles/1_Knapsack.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\1_Knapsack.dir\build.make CMakeFiles/1_Knapsack.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/1_Knapsack.dir/main.cpp.obj.provides

CMakeFiles/1_Knapsack.dir/main.cpp.obj.provides.build: CMakeFiles/1_Knapsack.dir/main.cpp.obj


# Object files for target 1_Knapsack
1_Knapsack_OBJECTS = \
"CMakeFiles/1_Knapsack.dir/main.cpp.obj"

# External object files for target 1_Knapsack
1_Knapsack_EXTERNAL_OBJECTS =

1_Knapsack.exe: CMakeFiles/1_Knapsack.dir/main.cpp.obj
1_Knapsack.exe: CMakeFiles/1_Knapsack.dir/build.make
1_Knapsack.exe: CMakeFiles/1_Knapsack.dir/linklibs.rsp
1_Knapsack.exe: CMakeFiles/1_Knapsack.dir/objects1.rsp
1_Knapsack.exe: CMakeFiles/1_Knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_Knapsack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1_Knapsack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_Knapsack.dir/build: 1_Knapsack.exe

.PHONY : CMakeFiles/1_Knapsack.dir/build

CMakeFiles/1_Knapsack.dir/requires: CMakeFiles/1_Knapsack.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/1_Knapsack.dir/requires

CMakeFiles/1_Knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1_Knapsack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1_Knapsack.dir/clean

CMakeFiles/1_Knapsack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack" "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack" "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\1 Knapsack\cmake-build-debug\CMakeFiles\1_Knapsack.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/1_Knapsack.dir/depend

