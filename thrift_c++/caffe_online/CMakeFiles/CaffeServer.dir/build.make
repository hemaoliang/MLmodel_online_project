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
CMAKE_SOURCE_DIR = /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online

# Include any dependencies generated for this target.
include CMakeFiles/CaffeServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CaffeServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CaffeServer.dir/flags.make

CMakeFiles/CaffeServer.dir/src/caffe_server.o: CMakeFiles/CaffeServer.dir/flags.make
CMakeFiles/CaffeServer.dir/src/caffe_server.o: src/caffe_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/CaffeServer.dir/src/caffe_server.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CaffeServer.dir/src/caffe_server.o -c /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/src/caffe_server.cpp

CMakeFiles/CaffeServer.dir/src/caffe_server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CaffeServer.dir/src/caffe_server.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/src/caffe_server.cpp > CMakeFiles/CaffeServer.dir/src/caffe_server.i

CMakeFiles/CaffeServer.dir/src/caffe_server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CaffeServer.dir/src/caffe_server.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/src/caffe_server.cpp -o CMakeFiles/CaffeServer.dir/src/caffe_server.s

CMakeFiles/CaffeServer.dir/src/caffe_server.o.requires:
.PHONY : CMakeFiles/CaffeServer.dir/src/caffe_server.o.requires

CMakeFiles/CaffeServer.dir/src/caffe_server.o.provides: CMakeFiles/CaffeServer.dir/src/caffe_server.o.requires
	$(MAKE) -f CMakeFiles/CaffeServer.dir/build.make CMakeFiles/CaffeServer.dir/src/caffe_server.o.provides.build
.PHONY : CMakeFiles/CaffeServer.dir/src/caffe_server.o.provides

CMakeFiles/CaffeServer.dir/src/caffe_server.o.provides.build: CMakeFiles/CaffeServer.dir/src/caffe_server.o

# Object files for target CaffeServer
CaffeServer_OBJECTS = \
"CMakeFiles/CaffeServer.dir/src/caffe_server.o"

# External object files for target CaffeServer
CaffeServer_EXTERNAL_OBJECTS =

bin/CaffeServer: CMakeFiles/CaffeServer.dir/src/caffe_server.o
bin/CaffeServer: CMakeFiles/CaffeServer.dir/build.make
bin/CaffeServer: lib/libcaffemodel.a
bin/CaffeServer: lib/libgencpp.a
bin/CaffeServer: CMakeFiles/CaffeServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/CaffeServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CaffeServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CaffeServer.dir/build: bin/CaffeServer
.PHONY : CMakeFiles/CaffeServer.dir/build

CMakeFiles/CaffeServer.dir/requires: CMakeFiles/CaffeServer.dir/src/caffe_server.o.requires
.PHONY : CMakeFiles/CaffeServer.dir/requires

CMakeFiles/CaffeServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CaffeServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CaffeServer.dir/clean

CMakeFiles/CaffeServer.dir/depend:
	cd /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online /home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/CMakeFiles/CaffeServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CaffeServer.dir/depend
