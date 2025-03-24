cmake_minimum_required(VERSION 3.23)
project(OnePacket)

if ((CMAKE_CXX_STANDARD EQUAL 98) OR (CMAKE_CXX_STANDARD EQUAL 03))
    message(ERROR "This library need C++ 11 or above.")
endif ()

option(COMPILE_OP_EXAMPLE "" ON)
option(COMPILE_OP_CTEST "" ON)

file(GLOB_RECURSE SRC_FILES "src/*.c" "src/*.h" "src/*.cpp" "src/*.hpp")

add_library(OnePacket SHARED
        include/serialize.h
        include/deserialize.h
        include/packets/CustomControllerPacket.h
        ${SRC_FILES}
)

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