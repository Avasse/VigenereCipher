cmake_minimum_required(VERSION 3.8)
project(Broke)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(Broke ${SOURCE_FILES})