#当前工程的名称
PROJECT(thrift_demo)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#将当前目录中的源文件名称赋值给变量 DIR_SRCS
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#查找系统安装的boost库的路径
find_package(Boost 1.53.0 REQUIRED)
#包含boost库的include文件路径
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")

message(${Boost_INCLUDE_DIRS})

#Make sure gen-cpp files can be included
#CMAKE_CURRENT_BINARY_DIR 外部编译时，指的是target目录，内部编译时，指的是顶级目录
#CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在的路径
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/gen-cpp")
#PROJECT_SOURCE_DIR 工程的根目录
include_directories("${PROJECT_SOURCE_DIR}/lib/cpp/src")

include_directories("/home/spongebob/software/thrift-0.9.3")

#指定依赖的第三方库 -L -I
include_directories("/usr/local/lib")
include_directories("/usr/local/include/thrift")

#Contains the thrift specific ADD_LIBRARY_THRIFT and TARGET_LINK_LIBRARIES_THRIFT
include("/home/spongebob/software/thrift-0.9.3/build/cmake/ThriftMacros.cmake")

#  set(<variable> <value1> ... <valueN>)
#　在这种情形下，<variable>被设置为一个各个值之间由分号分隔的list
set(tutorialgencpp_SOURCES 
    gen-cpp/Calculator.cpp
    gen-cpp/SharedService.cpp
    gen-cpp/shared_constants.cpp
    gen-cpp/shared_types.cpp
    gen-cpp/tutorial_constants.cpp
    gen-cpp/tutorial_types.cpp
)

add_library(tutorialgencpp STATIC ${tutorialgencpp_SOURCES})
#LINK_AGAINST_THRIFT_LIBRARY(tutorialgencpp thrift)
target_link_libraries(tutorialgencpp libthrift.so)

add_custom_command(OUTPUT gen-cpp/Calculator.cpp gen-cpp/SharedService.cpp gen-cpp/shared_constants.cpp gen-cpp/shared_types.cpp gen-cpp/tutorial_constants.cpp gen-cpp/tutorial_types.cpp
    COMMAND thrift-compiler --gen cpp -r ${PROJECT_SOURCE_DIR}/tutorial/tutorial.thrift
)

add_executable(TutorialServer CppServer.cpp)
target_link_libraries(TutorialServer tutorialgencpp)
#LINK_AGAINST_THRIFT_LIBRARY(TutorialServer thrift)

add_executable(TutorialClient CppClient.cpp)
target_link_libraries(TutorialClient tutorialgencpp)
#LINK_AGAINST_THRIFT_LIBRARY(TutorialClient thrift)

