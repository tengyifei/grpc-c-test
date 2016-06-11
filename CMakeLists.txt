cmake_minimum_required(VERSION 3.5)
project(test_grpc_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp test_config.h test_config.c)
add_executable(test_grpc_c ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(test_grpc_c grpc gpr)