cmake_minimum_required(VERSION 3.8)
project(Karp_Rabin)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp rolling_hash.h rolling_hash.cpp )
add_executable(Karp_Rabin ${SOURCE_FILES})