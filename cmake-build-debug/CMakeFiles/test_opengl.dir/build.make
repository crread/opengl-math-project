# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\berthelot Mickael\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\berthelot Mickael\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/test_opengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_opengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_opengl.dir/flags.make

CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj: CMakeFiles/test_opengl.dir/flags.make
CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj: CMakeFiles/test_opengl.dir/includes_CXX.rsp
CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj: ../Dragon3DLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_opengl.dir\Dragon3DLight.cpp.obj -c "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\Dragon3DLight.cpp"

CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\Dragon3DLight.cpp" > CMakeFiles\test_opengl.dir\Dragon3DLight.cpp.i

CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\Dragon3DLight.cpp" -o CMakeFiles\test_opengl.dir\Dragon3DLight.cpp.s

# Object files for target test_opengl
test_opengl_OBJECTS = \
"CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj"

# External object files for target test_opengl
test_opengl_EXTERNAL_OBJECTS =

test_opengl.exe: CMakeFiles/test_opengl.dir/Dragon3DLight.cpp.obj
test_opengl.exe: CMakeFiles/test_opengl.dir/build.make
test_opengl.exe: CMakeFiles/test_opengl.dir/linklibs.rsp
test_opengl.exe: CMakeFiles/test_opengl.dir/objects1.rsp
test_opengl.exe: CMakeFiles/test_opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_opengl.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_opengl.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_opengl.dir/build: test_opengl.exe

.PHONY : CMakeFiles/test_opengl.dir/build

CMakeFiles/test_opengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_opengl.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_opengl.dir/clean

CMakeFiles/test_opengl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project" "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project" "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug" "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug" "C:\Users\berthelot Mickael\Desktop\opengl projets\opengl-math-project\cmake-build-debug\CMakeFiles\test_opengl.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_opengl.dir/depend

