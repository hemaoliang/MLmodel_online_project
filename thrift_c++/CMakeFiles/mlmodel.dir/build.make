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
include CMakeFiles/mlmodel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mlmodel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mlmodel.dir/flags.make

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o: CMakeFiles/mlmodel.dir/flags.make
CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o: src/ml_libs/libsvm/svm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o -c /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/svm.cpp

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/svm.cpp > CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.i

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/svm.cpp -o CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.s

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.requires:
.PHONY : CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.requires

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.provides: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.requires
	$(MAKE) -f CMakeFiles/mlmodel.dir/build.make CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.provides.build
.PHONY : CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.provides

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.provides.build: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o: CMakeFiles/mlmodel.dir/flags.make
CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o: src/ml_libs/libsvm/eval.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o -c /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/eval.cpp

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/eval.cpp > CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.i

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_libs/libsvm/eval.cpp -o CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.s

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.requires:
.PHONY : CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.requires

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.provides: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.requires
	$(MAKE) -f CMakeFiles/mlmodel.dir/build.make CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.provides.build
.PHONY : CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.provides

CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.provides.build: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o: CMakeFiles/mlmodel.dir/flags.make
CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o: src/ml_models/mlmodel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o -c /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_models/mlmodel.cpp

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_models/mlmodel.cpp > CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.i

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spongebob/MLmodel_online_project/thrift_c++/src/ml_models/mlmodel.cpp -o CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.s

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.requires:
.PHONY : CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.requires

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.provides: CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.requires
	$(MAKE) -f CMakeFiles/mlmodel.dir/build.make CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.provides.build
.PHONY : CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.provides

CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.provides.build: CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o

# Object files for target mlmodel
mlmodel_OBJECTS = \
"CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o" \
"CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o" \
"CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o"

# External object files for target mlmodel
mlmodel_EXTERNAL_OBJECTS =

lib/libmlmodel.a: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o
lib/libmlmodel.a: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o
lib/libmlmodel.a: CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o
lib/libmlmodel.a: CMakeFiles/mlmodel.dir/build.make
lib/libmlmodel.a: CMakeFiles/mlmodel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library lib/libmlmodel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mlmodel.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mlmodel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mlmodel.dir/build: lib/libmlmodel.a
.PHONY : CMakeFiles/mlmodel.dir/build

CMakeFiles/mlmodel.dir/requires: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/svm.o.requires
CMakeFiles/mlmodel.dir/requires: CMakeFiles/mlmodel.dir/src/ml_libs/libsvm/eval.o.requires
CMakeFiles/mlmodel.dir/requires: CMakeFiles/mlmodel.dir/src/ml_models/mlmodel.o.requires
.PHONY : CMakeFiles/mlmodel.dir/requires

CMakeFiles/mlmodel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mlmodel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mlmodel.dir/clean

CMakeFiles/mlmodel.dir/depend:
	cd /home/spongebob/MLmodel_online_project/thrift_c++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++ /home/spongebob/MLmodel_online_project/thrift_c++/CMakeFiles/mlmodel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mlmodel.dir/depend

