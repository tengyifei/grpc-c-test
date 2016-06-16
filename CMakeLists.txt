cmake_minimum_required(VERSION 3.5)
project(test_grpc_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test_config.h test_config.c grpc/impl/unary_blocking_call.c grpc/impl/unary_blocking_call.h grpc/impl/init_shutdown.c grpc/impl/init_shutdown.h mock_helloworld.grpc.pb.c mock_helloworld.grpc.pb.h main.c grpc/grpc_c_public.h grpc/impl/call_ops.h grpc/impl/call_ops.c grpc/impl/context.c grpc/impl/context.h grpc/status_code_public.h grpc/status_public.h grpc/channel_public.h grpc/impl/channel.c grpc/impl/status.h)
add_executable(test_grpc_c ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(test_grpc_c grpc gpr)