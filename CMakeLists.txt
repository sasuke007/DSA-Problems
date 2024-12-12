cmake_minimum_required(VERSION 3.19)
project(DSA_Problems)

set(CMAKE_CXX_STANDARD 20)

# Check if _DEBUG is defined, and if so, add the definition
if (_DEBUG)
    add_definitions(-D_DEBUG)
endif()

add_executable(DSA_Problems main.cpp)
