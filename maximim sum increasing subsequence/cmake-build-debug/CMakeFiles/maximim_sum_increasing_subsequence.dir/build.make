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
CMAKE_SOURCE_DIR = "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/maximim_sum_increasing_subsequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/maximim_sum_increasing_subsequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maximim_sum_increasing_subsequence.dir/flags.make

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj: CMakeFiles/maximim_sum_increasing_subsequence.dir/flags.make
CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\maximim_sum_increasing_subsequence.dir\main.cpp.obj -c "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\main.cpp"

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\main.cpp" > CMakeFiles\maximim_sum_increasing_subsequence.dir\main.cpp.i

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\main.cpp" -o CMakeFiles\maximim_sum_increasing_subsequence.dir\main.cpp.s

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.requires

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.provides: CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\maximim_sum_increasing_subsequence.dir\build.make CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.provides

CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.provides.build: CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj


# Object files for target maximim_sum_increasing_subsequence
maximim_sum_increasing_subsequence_OBJECTS = \
"CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj"

# External object files for target maximim_sum_increasing_subsequence
maximim_sum_increasing_subsequence_EXTERNAL_OBJECTS =

maximim_sum_increasing_subsequence.exe: CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj
maximim_sum_increasing_subsequence.exe: CMakeFiles/maximim_sum_increasing_subsequence.dir/build.make
maximim_sum_increasing_subsequence.exe: CMakeFiles/maximim_sum_increasing_subsequence.dir/linklibs.rsp
maximim_sum_increasing_subsequence.exe: CMakeFiles/maximim_sum_increasing_subsequence.dir/objects1.rsp
maximim_sum_increasing_subsequence.exe: CMakeFiles/maximim_sum_increasing_subsequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable maximim_sum_increasing_subsequence.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\maximim_sum_increasing_subsequence.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maximim_sum_increasing_subsequence.dir/build: maximim_sum_increasing_subsequence.exe

.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/build

CMakeFiles/maximim_sum_increasing_subsequence.dir/requires: CMakeFiles/maximim_sum_increasing_subsequence.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/requires

CMakeFiles/maximim_sum_increasing_subsequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\maximim_sum_increasing_subsequence.dir\cmake_clean.cmake
.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/clean

CMakeFiles/maximim_sum_increasing_subsequence.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence" "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence" "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\maximim sum increasing subsequence\cmake-build-debug\CMakeFiles\maximim_sum_increasing_subsequence.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/maximim_sum_increasing_subsequence.dir/depend

