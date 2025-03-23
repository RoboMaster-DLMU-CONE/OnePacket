cmake_minimum_required(VERSION 3.30)
project(OnePacket)

set(CMAKE_CXX_STANDARD 20)

add_library(OnePacket SHARED
        include/packet.h
        src/packet.cpp
        src/CustomFunction/CustomFunction.hpp
        src/CustomFunction/CustomControlPacketFunction.hpp
        src/PacketBase.hpp)

target_include_directories(OnePacket PUBLIC include)

add_executable(C_Example example/cExample.c)
target_link_libraries(C_Example PRIVATE OnePacket)