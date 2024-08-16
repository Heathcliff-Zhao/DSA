cmake_minimum_required(VERSION 3.10)
project(dsa-from-scratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB CPP_FILES "include/*.cpp")

foreach(CPP_FILE ${CPP_FILES})
        get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
        add_executable(${EXE_NAME} ${CPP_FILE})
endforeach()

add_executable(dsa-from-scratch src/main.cpp)