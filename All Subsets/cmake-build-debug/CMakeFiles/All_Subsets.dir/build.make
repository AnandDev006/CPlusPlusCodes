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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\CODE\C++\All Subsets"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\C++\All Subsets\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/All_Subsets.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/All_Subsets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/All_Subsets.dir/flags.make

CMakeFiles/All_Subsets.dir/main.cpp.obj: CMakeFiles/All_Subsets.dir/flags.make
CMakeFiles/All_Subsets.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\C++\All Subsets\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/All_Subsets.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\All_Subsets.dir\main.cpp.obj -c "E:\CODE\C++\All Subsets\main.cpp"

CMakeFiles/All_Subsets.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/All_Subsets.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\C++\All Subsets\main.cpp" > CMakeFiles\All_Subsets.dir\main.cpp.i

CMakeFiles/All_Subsets.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/All_Subsets.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\C++\All Subsets\main.cpp" -o CMakeFiles\All_Subsets.dir\main.cpp.s

CMakeFiles/All_Subsets.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/All_Subsets.dir/main.cpp.obj.requires

CMakeFiles/All_Subsets.dir/main.cpp.obj.provides: CMakeFiles/All_Subsets.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\All_Subsets.dir\build.make CMakeFiles/All_Subsets.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/All_Subsets.dir/main.cpp.obj.provides

CMakeFiles/All_Subsets.dir/main.cpp.obj.provides.build: CMakeFiles/All_Subsets.dir/main.cpp.obj


# Object files for target All_Subsets
All_Subsets_OBJECTS = \
"CMakeFiles/All_Subsets.dir/main.cpp.obj"

# External object files for target All_Subsets
All_Subsets_EXTERNAL_OBJECTS =

All_Subsets.exe: CMakeFiles/All_Subsets.dir/main.cpp.obj
All_Subsets.exe: CMakeFiles/All_Subsets.dir/build.make
All_Subsets.exe: CMakeFiles/All_Subsets.dir/linklibs.rsp
All_Subsets.exe: CMakeFiles/All_Subsets.dir/objects1.rsp
All_Subsets.exe: CMakeFiles/All_Subsets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\C++\All Subsets\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable All_Subsets.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\All_Subsets.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/All_Subsets.dir/build: All_Subsets.exe

.PHONY : CMakeFiles/All_Subsets.dir/build

CMakeFiles/All_Subsets.dir/requires: CMakeFiles/All_Subsets.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/All_Subsets.dir/requires

CMakeFiles/All_Subsets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\All_Subsets.dir\cmake_clean.cmake
.PHONY : CMakeFiles/All_Subsets.dir/clean

CMakeFiles/All_Subsets.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\C++\All Subsets" "E:\CODE\C++\All Subsets" "E:\CODE\C++\All Subsets\cmake-build-debug" "E:\CODE\C++\All Subsets\cmake-build-debug" "E:\CODE\C++\All Subsets\cmake-build-debug\CMakeFiles\All_Subsets.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/All_Subsets.dir/depend

