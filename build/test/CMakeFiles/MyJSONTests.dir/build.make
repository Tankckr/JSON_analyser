# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build

# Include any dependencies generated for this target.
include test/CMakeFiles/MyJSONTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/MyJSONTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/MyJSONTests.dir/flags.make

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o: ../src/MyJSON_Value/Global_JSON.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/Global_JSON.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/Global_JSON.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/Global_JSON.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o: ../src/MyJSON_Value/JSON_Array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Array.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Array.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Array.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o: ../src/MyJSON_Value/JSON_Bool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Bool.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Bool.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Bool.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o: ../src/MyJSON_Value/JSON_Error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Error.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Error.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Error.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o: ../src/MyJSON_Value/JSON_NULL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_NULL.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_NULL.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_NULL.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o: ../src/MyJSON_Value/JSON_Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Number.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Number.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Number.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o: ../src/MyJSON_Value/JSON_Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Object.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Object.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Object.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o: ../src/MyJSON_Value/JSON_String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_String.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_String.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_String.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o: ../src/MyJSON_Value/JSON_Value.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Value.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Value.cpp > CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/MyJSON_Value/JSON_Value.cpp -o CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o: ../src/SAJ/SAJ.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o: ../src/SAJ/SAJ_Array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Array.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Array.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Array.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o: ../src/SAJ/SAJ_Bool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Bool.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Bool.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Bool.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o: ../src/SAJ/SAJ_Null.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Null.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Null.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Null.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o: ../src/SAJ/SAJ_Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Number.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Number.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Number.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o: ../src/SAJ/SAJ_Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Object.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Object.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Object.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o: ../src/SAJ/SAJ_String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_String.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_String.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_String.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o: ../src/SAJ/SAJ_Value.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Value.cpp

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Value.cpp > CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/src/SAJ/SAJ_Value.cpp -o CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.s

test/CMakeFiles/MyJSONTests.dir/__/test.cpp.o: test/CMakeFiles/MyJSONTests.dir/flags.make
test/CMakeFiles/MyJSONTests.dir/__/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object test/CMakeFiles/MyJSONTests.dir/__/test.cpp.o"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyJSONTests.dir/__/test.cpp.o -c /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/test.cpp

test/CMakeFiles/MyJSONTests.dir/__/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyJSONTests.dir/__/test.cpp.i"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/test.cpp > CMakeFiles/MyJSONTests.dir/__/test.cpp.i

test/CMakeFiles/MyJSONTests.dir/__/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyJSONTests.dir/__/test.cpp.s"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/test.cpp -o CMakeFiles/MyJSONTests.dir/__/test.cpp.s

# Object files for target MyJSONTests
MyJSONTests_OBJECTS = \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o" \
"CMakeFiles/MyJSONTests.dir/__/test.cpp.o"

# External object files for target MyJSONTests
MyJSONTests_EXTERNAL_OBJECTS =

test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/Global_JSON.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Array.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Bool.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Error.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_NULL.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Number.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Object.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_String.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/MyJSON_Value/JSON_Value.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Array.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Bool.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Null.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Number.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Object.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_String.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/src/SAJ/SAJ_Value.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/__/test.cpp.o
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/build.make
test/MyJSONTests: /usr/local/lib/libgtest.a
test/MyJSONTests: test/CMakeFiles/MyJSONTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable MyJSONTests"
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyJSONTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/MyJSONTests.dir/build: test/MyJSONTests

.PHONY : test/CMakeFiles/MyJSONTests.dir/build

test/CMakeFiles/MyJSONTests.dir/clean:
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test && $(CMAKE_COMMAND) -P CMakeFiles/MyJSONTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/MyJSONTests.dir/clean

test/CMakeFiles/MyJSONTests.dir/depend:
	cd /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/test /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test /home/scutech/Desktop/codes/JSON_analyser/JSON_analyser/build/test/CMakeFiles/MyJSONTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/MyJSONTests.dir/depend

