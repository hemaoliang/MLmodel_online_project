# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/spongebob/MLmodel_online_project/thrift_c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spongebob/MLmodel_online_project/thrift_c++

# Include any dependencies generated for this target.
include CMakeFiles/MlModelClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MlModelClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MlModelClient.dir/flags.make

CMakeFiles/MlModelClient.dir/src/MlModelClient.o: CMakeFiles/MlModelClient.dir/flags.make
CMakeFiles/MlModelClient.dir/src/MlModelClient.o: src/MlModelClient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MlModelClient.dir/src/MlModelClient.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MlModelClient.dir/src/MlModelClient.o -c /home/spongebob/MLmodel_online_project/thrift_c++/src/MlModelClient.cpp

CMakeFiles/MlModelClient.dir/src/MlModelClient.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MlModelClient.dir/src/MlModelClient.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spongebob/MLmodel_online_project/thrift_c++/src/MlModelClient.cpp > CMakeFiles/MlModelClient.dir/src/MlModelClient.i

CMakeFiles/MlModelClient.dir/src/MlModelClient.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MlModelClient.dir/src/MlModelClient.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spongebob/MLmodel_online_project/thrift_c++/src/MlModelClient.cpp -o CMakeFiles/MlModelClient.dir/src/MlModelClient.s

CMakeFiles/MlModelClient.dir/src/MlModelClient.o.requires:
.PHONY : CMakeFiles/MlModelClient.dir/src/MlModelClient.o.requires

CMakeFiles/MlModelClient.dir/src/MlModelClient.o.provides: CMakeFiles/MlModelClient.dir/src/MlModelClient.o.requires
	$(MAKE) -f CMakeFiles/MlModelClient.dir/build.make CMakeFiles/MlModelClient.dir/src/MlModelClient.o.provides.build
.PHONY : CMakeFiles/MlModelClient.dir/src/MlModelClient.o.provides

CMakeFiles/MlModelClient.dir/src/MlModelClient.o.provides.build: CMakeFiles/MlModelClient.dir/src/MlModelClient.o

# Object files for target MlModelClient
MlModelClient_OBJECTS = \
"CMakeFiles/MlModelClient.dir/src/MlModelClient.o"

# External object files for target MlModelClient
MlModelClient_EXTERNAL_OBJECTS =

bin/MlModelClient: CMakeFiles/MlModelClient.dir/src/MlModelClient.o
bin/MlModelClient: CMakeFiles/MlModelClient.dir/build.make
bin/MlModelClient: lib/libmlmodel.a
bin/MlModelClient: lib/libgencpp.a
bin/MlModelClient: CMakeFiles/MlModelClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/MlModelClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MlModelClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MlModelClient.dir/build: bin/MlModelClient
.PHONY : CMakeFiles/MlModelClient.dir/build

CMakeFiles/MlModelClient.dir/requires: CMakeFiles/MlModelClient.dir/src/MlModelClient.o.requires
.PHONY : CMakeFiles/MlModelClient.dir/requires

CMakeFiles/MlModelClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MlModelClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MlModelClient.dir/clean

CMakeFiles/MlModelClient.dir/depend:
	cd /home/spongebob/MLmodel_online_project/thrift_c++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles/MlModelClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MlModelClient.dir/depend

