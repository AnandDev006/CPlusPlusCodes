# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = "E:\CODE\C++\smallest from sub array"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\C++\smallest from sub array\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/smallest_from_sub_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smallest_from_sub_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smallest_from_sub_array.dir/flags.make

CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj: CMakeFiles/smallest_from_sub_array.dir/flags.make
CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\C++\smallest from sub array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\smallest_from_sub_array.dir\main.cpp.obj -c "E:\CODE\C++\smallest from sub array\main.cpp"

CMakeFiles/smallest_from_sub_array.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smallest_from_sub_array.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\C++\smallest from sub array\main.cpp" > CMakeFiles\smallest_from_sub_array.dir\main.cpp.i

CMakeFiles/smallest_from_sub_array.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smallest_from_sub_array.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\C++\smallest from sub array\main.cpp" -o CMakeFiles\smallest_from_sub_array.dir\main.cpp.s

CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.requires

CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.provides: CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\smallest_from_sub_array.dir\build.make CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.provides

CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.provides.build: CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj


# Object files for target smallest_from_sub_array
smallest_from_sub_array_OBJECTS = \
"CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj"

# External object files for target smallest_from_sub_array
smallest_from_sub_array_EXTERNAL_OBJECTS =

smallest_from_sub_array.exe: CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj
smallest_from_sub_array.exe: CMakeFiles/smallest_from_sub_array.dir/build.make
smallest_from_sub_array.exe: CMakeFiles/smallest_from_sub_array.dir/linklibs.rsp
smallest_from_sub_array.exe: CMakeFiles/smallest_from_sub_array.dir/objects1.rsp
smallest_from_sub_array.exe: CMakeFiles/smallest_from_sub_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\C++\smallest from sub array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable smallest_from_sub_array.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\smallest_from_sub_array.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smallest_from_sub_array.dir/build: smallest_from_sub_array.exe

.PHONY : CMakeFiles/smallest_from_sub_array.dir/build

CMakeFiles/smallest_from_sub_array.dir/requires: CMakeFiles/smallest_from_sub_array.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/smallest_from_sub_array.dir/requires

CMakeFiles/smallest_from_sub_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\smallest_from_sub_array.dir\cmake_clean.cmake
.PHONY : CMakeFiles/smallest_from_sub_array.dir/clean

CMakeFiles/smallest_from_sub_array.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\C++\smallest from sub array" "E:\CODE\C++\smallest from sub array" "E:\CODE\C++\smallest from sub array\cmake-build-debug" "E:\CODE\C++\smallest from sub array\cmake-build-debug" "E:\CODE\C++\smallest from sub array\cmake-build-debug\CMakeFiles\smallest_from_sub_array.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/smallest_from_sub_array.dir/depend
