# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2018.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\96552\CLionProjects\project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\96552\CLionProjects\project3\release

# Include any dependencies generated for this target.
include CMakeFiles/rotate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rotate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rotate.dir/flags.make

CMakeFiles/rotate.dir/rotate.cpp.obj: CMakeFiles/rotate.dir/flags.make
CMakeFiles/rotate.dir/rotate.cpp.obj: ../rotate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\96552\CLionProjects\project3\release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rotate.dir/rotate.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\rotate.dir\rotate.cpp.obj -c C:\Users\96552\CLionProjects\project3\rotate.cpp

CMakeFiles/rotate.dir/rotate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rotate.dir/rotate.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\96552\CLionProjects\project3\rotate.cpp > CMakeFiles\rotate.dir\rotate.cpp.i

CMakeFiles/rotate.dir/rotate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rotate.dir/rotate.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\96552\CLionProjects\project3\rotate.cpp -o CMakeFiles\rotate.dir\rotate.cpp.s

CMakeFiles/rotate.dir/rotate.cpp.obj.requires:

.PHONY : CMakeFiles/rotate.dir/rotate.cpp.obj.requires

CMakeFiles/rotate.dir/rotate.cpp.obj.provides: CMakeFiles/rotate.dir/rotate.cpp.obj.requires
	$(MAKE) -f CMakeFiles\rotate.dir\build.make CMakeFiles/rotate.dir/rotate.cpp.obj.provides.build
.PHONY : CMakeFiles/rotate.dir/rotate.cpp.obj.provides

CMakeFiles/rotate.dir/rotate.cpp.obj.provides.build: CMakeFiles/rotate.dir/rotate.cpp.obj


# Object files for target rotate
rotate_OBJECTS = \
"CMakeFiles/rotate.dir/rotate.cpp.obj"

# External object files for target rotate
rotate_EXTERNAL_OBJECTS =

bin/rotate.exe: CMakeFiles/rotate.dir/rotate.cpp.obj
bin/rotate.exe: CMakeFiles/rotate.dir/build.make
bin/rotate.exe: CMakeFiles/rotate.dir/linklibs.rsp
bin/rotate.exe: CMakeFiles/rotate.dir/objects1.rsp
bin/rotate.exe: CMakeFiles/rotate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\96552\CLionProjects\project3\release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\rotate.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rotate.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rotate.dir/build: bin/rotate.exe

.PHONY : CMakeFiles/rotate.dir/build

CMakeFiles/rotate.dir/requires: CMakeFiles/rotate.dir/rotate.cpp.obj.requires

.PHONY : CMakeFiles/rotate.dir/requires

CMakeFiles/rotate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rotate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rotate.dir/clean

CMakeFiles/rotate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\96552\CLionProjects\project3 C:\Users\96552\CLionProjects\project3 C:\Users\96552\CLionProjects\project3\release C:\Users\96552\CLionProjects\project3\release C:\Users\96552\CLionProjects\project3\release\CMakeFiles\rotate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rotate.dir/depend

