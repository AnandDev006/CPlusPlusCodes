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
CMAKE_SOURCE_DIR = E:\CODE\OptimalBST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CODE\OptimalBST\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OptimalBST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OptimalBST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OptimalBST.dir/flags.make

CMakeFiles/OptimalBST.dir/main.cpp.obj: CMakeFiles/OptimalBST.dir/flags.make
CMakeFiles/OptimalBST.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CODE\OptimalBST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OptimalBST.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OptimalBST.dir\main.cpp.obj -c E:\CODE\OptimalBST\main.cpp

CMakeFiles/OptimalBST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OptimalBST.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CODE\OptimalBST\main.cpp > CMakeFiles\OptimalBST.dir\main.cpp.i

CMakeFiles/OptimalBST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OptimalBST.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CODE\OptimalBST\main.cpp -o CMakeFiles\OptimalBST.dir\main.cpp.s

CMakeFiles/OptimalBST.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/OptimalBST.dir/main.cpp.obj.requires

CMakeFiles/OptimalBST.dir/main.cpp.obj.provides: CMakeFiles/OptimalBST.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OptimalBST.dir\build.make CMakeFiles/OptimalBST.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/OptimalBST.dir/main.cpp.obj.provides

CMakeFiles/OptimalBST.dir/main.cpp.obj.provides.build: CMakeFiles/OptimalBST.dir/main.cpp.obj


# Object files for target OptimalBST
OptimalBST_OBJECTS = \
"CMakeFiles/OptimalBST.dir/main.cpp.obj"

# External object files for target OptimalBST
OptimalBST_EXTERNAL_OBJECTS =

OptimalBST.exe: CMakeFiles/OptimalBST.dir/main.cpp.obj
OptimalBST.exe: CMakeFiles/OptimalBST.dir/build.make
OptimalBST.exe: CMakeFiles/OptimalBST.dir/linklibs.rsp
OptimalBST.exe: CMakeFiles/OptimalBST.dir/objects1.rsp
OptimalBST.exe: CMakeFiles/OptimalBST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CODE\OptimalBST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OptimalBST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OptimalBST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OptimalBST.dir/build: OptimalBST.exe

.PHONY : CMakeFiles/OptimalBST.dir/build

CMakeFiles/OptimalBST.dir/requires: CMakeFiles/OptimalBST.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/OptimalBST.dir/requires

CMakeFiles/OptimalBST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OptimalBST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OptimalBST.dir/clean

CMakeFiles/OptimalBST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CODE\OptimalBST E:\CODE\OptimalBST E:\CODE\OptimalBST\cmake-build-debug E:\CODE\OptimalBST\cmake-build-debug E:\CODE\OptimalBST\cmake-build-debug\CMakeFiles\OptimalBST.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OptimalBST.dir/depend
