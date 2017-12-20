cmake_minimum_required(VERSION 3.8)
project(AVL_Trees)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AVL.cpp AVL.h)
add_executable(AVL_Trees ${SOURCE_FILES})