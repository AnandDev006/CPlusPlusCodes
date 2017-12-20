cmake_minimum_required(VERSION 3.8)
project(rolling_hash)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp rolling_hash.cpp rolling_hash.h )
add_executable(rolling_hash ${SOURCE_FILES})