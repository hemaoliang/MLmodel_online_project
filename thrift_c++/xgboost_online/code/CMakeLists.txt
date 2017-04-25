cmake_minimum_required (VERSION 3.5)
project (xgboost-predict)
find_package(OpenMP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

set(XGBOOST_HOME "/software/xgboost")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories (
    ${PROJECT_SOURCE_DIR}
    ${XGBOOST_HOME}/include 
    ${XGBOOST_HOME}/src
    ${XGBOOST_HOME}/dmlc-core/include
    ${XGBOOST_HOME}/rabit/include 
    )

link_directories(${XGBOOST_HOME}/dmlc-core ${XGBOOST_HOME}/rabit/lib ${XGBOOST_HOME}/lib)

set(SOURCES 
    xgboost_online_predict.cpp
)

add_executable(xgboost-predict ${SOURCES})

target_link_libraries(xgboost-predict dmlc)

target_link_libraries(xgboost-predict xgboost)

