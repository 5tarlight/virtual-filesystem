cmake_minimum_required(VERSION 3.28)
project(vfs)

message(STATUS "Compiler")
message(STATUS " - ID      : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path    : ${CMAKE_CXX_COMPILER}")

set(CMAKE_CXX_STANDARD 17)

add_executable(vfs main.cpp
        fs.h
        cli.h
)
