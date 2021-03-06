#当前工程的名称
PROJECT(caffe_online_thrift_c++)
CMAKE_MINIMUM_REQUIRED(VERSION 0.9.3)

#将当前目录中的源文件名称赋值给变量 DIR_SRCS
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#查找系统安装的boost库的路径
find_package(Boost 1.53.0 REQUIRED)
#包含boost库的include文件路径
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")

message(${Boost_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wconversion -O3 -fPIC")
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS "-fPIC")

#Make sure gen-cpp files can be included
#CMAKE_CURRENT_BINARY_DIR 外部编译时，指的是target目录，内部编译时，指的是顶级目录
#CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在的路径
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
#PROJECT_SOURCE_DIR 工程的顶级目录
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/test")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/gen-cpp")

#thrift 和 caffe 的源代码目录
include_directories("/home/spongebob/deeplearning/caffe-master/include")
include_directories("/home/spongebob/MLmodel_online_project/thrift_c++/caffe_online/include")
include_directories("/home/spongebob/deeplearning/caffe-master/build/src")
include_directories("/home/spongebob/software/thrift-0.9.3")

#指定依赖的第三方库 相当于gcc的 -I
include_directories("/usr/local/lib")
include_directories("/usr/local/include/thrift")
include_directories("/usr/local/include/libxml2")

#link_directories：动态链接库或静态链接库的搜索路径，相当于gcc的-L参数
link_directories("${PROJECT_SOURCE_DIR}/lib")
link_directories("/home/spongebob/deeplearning/caffe-master/build/lib")

#Contains the thrift specific ADD_LIBRARY_THRIFT and TARGET_LINK_LIBRARIES_THRIFT
include("/home/spongebob/software/thrift-0.9.3/build/cmake/ThriftMacros.cmake")

#  set(<variable> <value1> ... <valueN>)
#　在这种情形下，<variable>被设置为一个各个值之间由分号分隔的list
set(caffemodel_SOURCES 
    src/caffe_classifier.cpp
)

set(gencpp_SOURCES
    gen-cpp/caffe_server_constants.cpp
    gen-cpp/caffe_server_types.cpp
    gen-cpp/CaffeService.cpp
)

add_custom_command(OUTPUT gen-cpp/caffe_server_constants.cpp gen-cpp/caffe_server_types.cpp gen-cpp/CaffeService.cpp gen-cpp/CaffeService_server.skeleton.cpp
    COMMAND thrift --gen cpp -r ${PROJECT_SOURCE_DIR}/thrift/caffe_server.thrift
)

add_library(caffemodel STATIC ${caffemodel_SOURCES})

add_library(gencpp STATIC ${gencpp_SOURCES})

target_link_libraries(caffemodel libthrift.so libglog.so libcaffe.so 
	libopencv_core.so libopencv_highgui.so libopencv_imgproc.so librt.so  gencpp)

add_executable(CaffeServer src/caffe_server.cpp)
target_link_libraries(CaffeServer caffemodel)

add_executable(CaffeClient src/caffe_client.cpp)
target_link_libraries(CaffeClient caffemodel)

