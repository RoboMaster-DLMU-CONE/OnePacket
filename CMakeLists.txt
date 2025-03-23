cmake_minimum_required(VERSION 3.30)
project(OnePacket)

set(CMAKE_CXX_STANDARD 20)

add_library(OnePacket SHARED
        include/serialize.h
        src/serialize.cpp
        src/CustomFunction/CustomFunction.hpp
        src/CustomFunction/CustomControlPacketFunction.hpp
        src/PacketBase.hpp
        src/deserialize.cpp
        include/deserialize.h
        include/packets/CustomControllerPacket.h)

target_include_directories(OnePacket PUBLIC include)

add_executable(C_Example example/cExample.c)
target_link_libraries(C_Example PRIVATE OnePacket)