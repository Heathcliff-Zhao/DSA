cmake_minimum_required(VERSION 3.10)
project(dsa-from-scratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(dsa-from-scratch
        src/main.cpp)