# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ACER\Desktop\C++\Projet\build

# Include any dependencies generated for this target.
include CMakeFiles/tower.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tower.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tower.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tower.dir/flags.make

CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/GL/opengl_interface.cpp
CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj -MF CMakeFiles\tower.dir\src\GL\opengl_interface.cpp.obj.d -o CMakeFiles\tower.dir\src\GL\opengl_interface.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\GL\opengl_interface.cpp

CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\GL\opengl_interface.cpp > CMakeFiles\tower.dir\src\GL\opengl_interface.cpp.i

CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\GL\opengl_interface.cpp -o CMakeFiles\tower.dir\src\GL\opengl_interface.cpp.s

CMakeFiles/tower.dir/src/img/image.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/img/image.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/img/image.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/img/image.cpp
CMakeFiles/tower.dir/src/img/image.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tower.dir/src/img/image.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/img/image.cpp.obj -MF CMakeFiles\tower.dir\src\img\image.cpp.obj.d -o CMakeFiles\tower.dir\src\img\image.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\img\image.cpp

CMakeFiles/tower.dir/src/img/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/img/image.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\img\image.cpp > CMakeFiles\tower.dir\src\img\image.cpp.i

CMakeFiles/tower.dir/src/img/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/img/image.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\img\image.cpp -o CMakeFiles\tower.dir\src\img\image.cpp.s

CMakeFiles/tower.dir/src/aircraft.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/aircraft.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/aircraft.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/aircraft.cpp
CMakeFiles/tower.dir/src/aircraft.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tower.dir/src/aircraft.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/aircraft.cpp.obj -MF CMakeFiles\tower.dir\src\aircraft.cpp.obj.d -o CMakeFiles\tower.dir\src\aircraft.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\aircraft.cpp

CMakeFiles/tower.dir/src/aircraft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/aircraft.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\aircraft.cpp > CMakeFiles\tower.dir\src\aircraft.cpp.i

CMakeFiles/tower.dir/src/aircraft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/aircraft.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\aircraft.cpp -o CMakeFiles\tower.dir\src\aircraft.cpp.s

CMakeFiles/tower.dir/src/tower_sim.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/tower_sim.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/tower_sim.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/tower_sim.cpp
CMakeFiles/tower.dir/src/tower_sim.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tower.dir/src/tower_sim.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/tower_sim.cpp.obj -MF CMakeFiles\tower.dir\src\tower_sim.cpp.obj.d -o CMakeFiles\tower.dir\src\tower_sim.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower_sim.cpp

CMakeFiles/tower.dir/src/tower_sim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/tower_sim.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower_sim.cpp > CMakeFiles\tower.dir\src\tower_sim.cpp.i

CMakeFiles/tower.dir/src/tower_sim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/tower_sim.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower_sim.cpp -o CMakeFiles\tower.dir\src\tower_sim.cpp.s

CMakeFiles/tower.dir/src/tower.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/tower.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/tower.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/tower.cpp
CMakeFiles/tower.dir/src/tower.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tower.dir/src/tower.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/tower.cpp.obj -MF CMakeFiles\tower.dir\src\tower.cpp.obj.d -o CMakeFiles\tower.dir\src\tower.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower.cpp

CMakeFiles/tower.dir/src/tower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/tower.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower.cpp > CMakeFiles\tower.dir\src\tower.cpp.i

CMakeFiles/tower.dir/src/tower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/tower.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\tower.cpp -o CMakeFiles\tower.dir\src\tower.cpp.s

CMakeFiles/tower.dir/src/main.cpp.obj: CMakeFiles/tower.dir/flags.make
CMakeFiles/tower.dir/src/main.cpp.obj: CMakeFiles/tower.dir/includes_CXX.rsp
CMakeFiles/tower.dir/src/main.cpp.obj: C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/src/main.cpp
CMakeFiles/tower.dir/src/main.cpp.obj: CMakeFiles/tower.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tower.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tower.dir/src/main.cpp.obj -MF CMakeFiles\tower.dir\src\main.cpp.obj.d -o CMakeFiles\tower.dir\src\main.cpp.obj -c C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\main.cpp

CMakeFiles/tower.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tower.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\main.cpp > CMakeFiles\tower.dir\src\main.cpp.i

CMakeFiles/tower.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tower.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project\src\main.cpp -o CMakeFiles\tower.dir\src\main.cpp.s

# Object files for target tower
tower_OBJECTS = \
"CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj" \
"CMakeFiles/tower.dir/src/img/image.cpp.obj" \
"CMakeFiles/tower.dir/src/aircraft.cpp.obj" \
"CMakeFiles/tower.dir/src/tower_sim.cpp.obj" \
"CMakeFiles/tower.dir/src/tower.cpp.obj" \
"CMakeFiles/tower.dir/src/main.cpp.obj"

# External object files for target tower
tower_EXTERNAL_OBJECTS =

tower.exe: CMakeFiles/tower.dir/src/GL/opengl_interface.cpp.obj
tower.exe: CMakeFiles/tower.dir/src/img/image.cpp.obj
tower.exe: CMakeFiles/tower.dir/src/aircraft.cpp.obj
tower.exe: CMakeFiles/tower.dir/src/tower_sim.cpp.obj
tower.exe: CMakeFiles/tower.dir/src/tower.cpp.obj
tower.exe: CMakeFiles/tower.dir/src/main.cpp.obj
tower.exe: CMakeFiles/tower.dir/build.make
tower.exe: C:/msys64/mingw64/lib/libfreeglut.dll.a
tower.exe: CMakeFiles/tower.dir/linklibs.rsp
tower.exe: CMakeFiles/tower.dir/objects1.rsp
tower.exe: CMakeFiles/tower.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tower.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tower.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -E copy_directory C:/Users/ACER/Desktop/C++/Projet/CPP_Learning_Project/media C:/Users/ACER/Desktop/C++/Projet/build/media
	"C:\Program Files\CMake\bin\cmake.exe" -E copy_if_different C:/msys64/mingw64/bin/libfreeglut.dll C:/Users/ACER/Desktop/C++/Projet/build/

# Rule to build all files generated by this target.
CMakeFiles/tower.dir/build: tower.exe
.PHONY : CMakeFiles/tower.dir/build

CMakeFiles/tower.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tower.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tower.dir/clean

CMakeFiles/tower.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project C:\Users\ACER\Desktop\C++\Projet\CPP_Learning_Project C:\Users\ACER\Desktop\C++\Projet\build C:\Users\ACER\Desktop\C++\Projet\build C:\Users\ACER\Desktop\C++\Projet\build\CMakeFiles\tower.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tower.dir/depend

