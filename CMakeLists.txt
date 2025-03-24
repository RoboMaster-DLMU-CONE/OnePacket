cmake_minimum_required(VERSION 3.30)
project(OnePacket)

if ((CMAKE_CXX_STANDARD EQUAL 98) OR (CMAKE_CXX_STANDARD EQUAL 03))
    message(ERROR "This library need C++ 11 or above.")
endif ()

option(COMPILE_OP_EXAMPLE "" ON)
option(COMPILE_OP_CTEST "" ON)

add_library(OnePacket SHARED
        include/serialize.h
        src/serialize.cpp
        src/CustomFunction/DJICRC/DJICRC.c
        src/CustomFunction/DJICRC/DJICRC.h
        src/CustomFunction/CustomFunction.hpp
        src/CustomFunction/CustomControlPacketFunction.hpp
        src/PacketBase.hpp
        src/deserialize.cpp
        include/deserialize.h
        include/packets/CustomControllerPacket.h)

target_include_directories(OnePacket PUBLIC include)

if (COMPILE_OP_EXAMPLE)
    add_executable(C_Example example/cExample.c)
    target_link_libraries(C_Example PRIVATE OnePacket)
endif ()

if (COMPILE_OP_CTEST)
    include(CTest)
    add_executable(CustomControlPacketTest test/CustomControlPacket.c)
    target_link_libraries(CustomControlPacketTest OnePacket)
    add_test(NAME CustomControlPacketTest
            COMMAND CustomControlPacketTest
    )
endif ()