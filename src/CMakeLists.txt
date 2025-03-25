cmake_minimum_required(VERSION 3.23)
project(OnePacketSrc)

file(GLOB_RECURSE C_SRC_FILES "*.c")
file(GLOB_RECURSE C_HEADER_FILES "*.h")
file(GLOB_RECURSE CPP_SRC_FILES "*.cpp")
file(GLOB_RECURSE CPP_HEADER_FILES "*.hpp")
set_source_files_properties(${CPP_SRC_FILES} ${CPP_HEADER_FILES} PROPERTIES LANGUAGE CXX)

add_library(OnePacketSrc SHARED
        ${C_SRC_FILES} ${C_HEADER_FILES}
        ${CPP_SRC_FILES} ${CPP_HEADER_FILES}
)

target_include_directories(OnePacketSrc PRIVATE include)
target_include_directories(OnePacketSrc PRIVATE ../include)

