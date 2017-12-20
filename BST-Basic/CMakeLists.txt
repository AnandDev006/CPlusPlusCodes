cmake_minimum_required(VERSION 3.7)
project(BST_Basic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BST.cpp BST.h)
add_executable(BST_Basic ${SOURCE_FILES})