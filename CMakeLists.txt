cmake_minimum_required(VERSION 3.23)
project(OnePacket)

if ((CMAKE_CXX_STANDARD EQUAL 98) OR (CMAKE_CXX_STANDARD EQUAL 03))
    message(ERROR "This library need C++ 11 or above.")
endif ()

set(CMAKE_CXX_STANDARD 11)

option(COMPILE_OP_EXAMPLE "" ON)
option(COMPILE_OP_CTEST "" ON)

file(GLOB_RECURSE C_SRC_FILES "src/*.c")
file(GLOB_RECURSE C_HEADER_FILES "src/*.h")
file(GLOB_RECURSE CPP_SRC_FILES "src/*.cpp")
file(GLOB_RECURSE CPP_HEADER_FILES "src/*.hpp")

# Set language properties if needed
set_source_files_properties(${CPP_SRC_FILES} ${CPP_HEADER_FILES} PROPERTIES LANGUAGE CXX)

add_subdirectory(src)

add_library(OnePacket SHARED
        include/serialize.h
        include/deserialize.h
        include/packets/CustomControllerPacket.h
)

set_target_properties(OnePacket PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(OnePacket PUBLIC include)
target_link_libraries(OnePacket PUBLIC OnePacketSrc)

if (WIN32)
    add_custom_command(TARGET OnePacket POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:OnePacketSrc>
            $<TARGET_FILE_DIR:CustomControlPacketTest>
    )
endif ()

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