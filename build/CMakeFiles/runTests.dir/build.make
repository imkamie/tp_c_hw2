# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/tp_c_hw2/tp_c_hw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/tp_c_hw2/tp_c_hw2/build

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/tests/run_tests.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/tests/run_tests.cpp.o: ../tests/run_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/tests/run_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/tests/run_tests.cpp.o -c /home/runner/work/tp_c_hw2/tp_c_hw2/tests/run_tests.cpp

CMakeFiles/runTests.dir/tests/run_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests/run_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/tp_c_hw2/tp_c_hw2/tests/run_tests.cpp > CMakeFiles/runTests.dir/tests/run_tests.cpp.i

CMakeFiles/runTests.dir/tests/run_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests/run_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/tp_c_hw2/tp_c_hw2/tests/run_tests.cpp -o CMakeFiles/runTests.dir/tests/run_tests.cpp.s

CMakeFiles/runTests.dir/tests/consistent_test.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/tests/consistent_test.cpp.o: ../tests/consistent_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTests.dir/tests/consistent_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/tests/consistent_test.cpp.o -c /home/runner/work/tp_c_hw2/tp_c_hw2/tests/consistent_test.cpp

CMakeFiles/runTests.dir/tests/consistent_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests/consistent_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/tp_c_hw2/tp_c_hw2/tests/consistent_test.cpp > CMakeFiles/runTests.dir/tests/consistent_test.cpp.i

CMakeFiles/runTests.dir/tests/consistent_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests/consistent_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/tp_c_hw2/tp_c_hw2/tests/consistent_test.cpp -o CMakeFiles/runTests.dir/tests/consistent_test.cpp.s

CMakeFiles/runTests.dir/tests/parallel_test.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/tests/parallel_test.cpp.o: ../tests/parallel_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runTests.dir/tests/parallel_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/tests/parallel_test.cpp.o -c /home/runner/work/tp_c_hw2/tp_c_hw2/tests/parallel_test.cpp

CMakeFiles/runTests.dir/tests/parallel_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests/parallel_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/tp_c_hw2/tp_c_hw2/tests/parallel_test.cpp > CMakeFiles/runTests.dir/tests/parallel_test.cpp.i

CMakeFiles/runTests.dir/tests/parallel_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests/parallel_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/tp_c_hw2/tp_c_hw2/tests/parallel_test.cpp -o CMakeFiles/runTests.dir/tests/parallel_test.cpp.s

CMakeFiles/runTests.dir/tests/stress_test.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/tests/stress_test.cpp.o: ../tests/stress_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/runTests.dir/tests/stress_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/tests/stress_test.cpp.o -c /home/runner/work/tp_c_hw2/tp_c_hw2/tests/stress_test.cpp

CMakeFiles/runTests.dir/tests/stress_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests/stress_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/tp_c_hw2/tp_c_hw2/tests/stress_test.cpp > CMakeFiles/runTests.dir/tests/stress_test.cpp.i

CMakeFiles/runTests.dir/tests/stress_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests/stress_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/tp_c_hw2/tp_c_hw2/tests/stress_test.cpp -o CMakeFiles/runTests.dir/tests/stress_test.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/tests/run_tests.cpp.o" \
"CMakeFiles/runTests.dir/tests/consistent_test.cpp.o" \
"CMakeFiles/runTests.dir/tests/parallel_test.cpp.o" \
"CMakeFiles/runTests.dir/tests/stress_test.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: CMakeFiles/runTests.dir/tests/run_tests.cpp.o
runTests: CMakeFiles/runTests.dir/tests/consistent_test.cpp.o
runTests: CMakeFiles/runTests.dir/tests/parallel_test.cpp.o
runTests: CMakeFiles/runTests.dir/tests/stress_test.cpp.o
runTests: CMakeFiles/runTests.dir/build.make
runTests: libconsistent.a
runTests: libparallel.so
runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
runTests: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable runTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests

.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /home/runner/work/tp_c_hw2/tp_c_hw2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/tp_c_hw2/tp_c_hw2 /home/runner/work/tp_c_hw2/tp_c_hw2 /home/runner/work/tp_c_hw2/tp_c_hw2/build /home/runner/work/tp_c_hw2/tp_c_hw2/build /home/runner/work/tp_c_hw2/tp_c_hw2/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTests.dir/depend

