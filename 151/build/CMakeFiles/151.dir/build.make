# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\BaiduSyncdisk\CodeCaprice\151

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\BaiduSyncdisk\CodeCaprice\151\build

# Include any dependencies generated for this target.
include CMakeFiles/151.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/151.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/151.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/151.dir/flags.make

CMakeFiles/151.dir/main.c.obj: CMakeFiles/151.dir/flags.make
CMakeFiles/151.dir/main.c.obj: D:/BaiduSyncdisk/CodeCaprice/151/main.c
CMakeFiles/151.dir/main.c.obj: CMakeFiles/151.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\BaiduSyncdisk\CodeCaprice\151\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/151.dir/main.c.obj"
	E:\Program\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/151.dir/main.c.obj -MF CMakeFiles\151.dir\main.c.obj.d -o CMakeFiles\151.dir\main.c.obj -c D:\BaiduSyncdisk\CodeCaprice\151\main.c

CMakeFiles/151.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/151.dir/main.c.i"
	E:\Program\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\BaiduSyncdisk\CodeCaprice\151\main.c > CMakeFiles\151.dir\main.c.i

CMakeFiles/151.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/151.dir/main.c.s"
	E:\Program\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\BaiduSyncdisk\CodeCaprice\151\main.c -o CMakeFiles\151.dir\main.c.s

# Object files for target 151
151_OBJECTS = \
"CMakeFiles/151.dir/main.c.obj"

# External object files for target 151
151_EXTERNAL_OBJECTS =

151.exe: CMakeFiles/151.dir/main.c.obj
151.exe: CMakeFiles/151.dir/build.make
151.exe: CMakeFiles/151.dir/linkLibs.rsp
151.exe: CMakeFiles/151.dir/objects1.rsp
151.exe: CMakeFiles/151.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\BaiduSyncdisk\CodeCaprice\151\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 151.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\151.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/151.dir/build: 151.exe
.PHONY : CMakeFiles/151.dir/build

CMakeFiles/151.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\151.dir\cmake_clean.cmake
.PHONY : CMakeFiles/151.dir/clean

CMakeFiles/151.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\BaiduSyncdisk\CodeCaprice\151 D:\BaiduSyncdisk\CodeCaprice\151 D:\BaiduSyncdisk\CodeCaprice\151\build D:\BaiduSyncdisk\CodeCaprice\151\build D:\BaiduSyncdisk\CodeCaprice\151\build\CMakeFiles\151.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/151.dir/depend

