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
CMAKE_SOURCE_DIR = "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/max_rect_area_hostogram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/max_rect_area_hostogram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/max_rect_area_hostogram.dir/flags.make

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj: CMakeFiles/max_rect_area_hostogram.dir/flags.make
CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\max_rect_area_hostogram.dir\main.cpp.obj -c "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\main.cpp"

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/max_rect_area_hostogram.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\main.cpp" > CMakeFiles\max_rect_area_hostogram.dir\main.cpp.i

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/max_rect_area_hostogram.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\main.cpp" -o CMakeFiles\max_rect_area_hostogram.dir\main.cpp.s

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.requires

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.provides: CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\max_rect_area_hostogram.dir\build.make CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.provides

CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.provides.build: CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj


# Object files for target max_rect_area_hostogram
max_rect_area_hostogram_OBJECTS = \
"CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj"

# External object files for target max_rect_area_hostogram
max_rect_area_hostogram_EXTERNAL_OBJECTS =

max_rect_area_hostogram.exe: CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj
max_rect_area_hostogram.exe: CMakeFiles/max_rect_area_hostogram.dir/build.make
max_rect_area_hostogram.exe: CMakeFiles/max_rect_area_hostogram.dir/linklibs.rsp
max_rect_area_hostogram.exe: CMakeFiles/max_rect_area_hostogram.dir/objects1.rsp
max_rect_area_hostogram.exe: CMakeFiles/max_rect_area_hostogram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable max_rect_area_hostogram.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\max_rect_area_hostogram.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/max_rect_area_hostogram.dir/build: max_rect_area_hostogram.exe

.PHONY : CMakeFiles/max_rect_area_hostogram.dir/build

CMakeFiles/max_rect_area_hostogram.dir/requires: CMakeFiles/max_rect_area_hostogram.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/max_rect_area_hostogram.dir/requires

CMakeFiles/max_rect_area_hostogram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\max_rect_area_hostogram.dir\cmake_clean.cmake
.PHONY : CMakeFiles/max_rect_area_hostogram.dir/clean

CMakeFiles/max_rect_area_hostogram.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram" "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram" "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug" "E:\CODE\GIT\CPlusPlusCodes\max rect area hostogram\cmake-build-debug\CMakeFiles\max_rect_area_hostogram.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/max_rect_area_hostogram.dir/depend

