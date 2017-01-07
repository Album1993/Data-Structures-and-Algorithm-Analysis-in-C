cmake_minimum_required(VERSION 3.6)
project(Data_Structures_and_Algorithm_Analysis_in_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LinkedList/list.c LinkedList/list.h main.c fatal.h LinkedList/testlist.c LinkedList/testlist.h polynomials/polynomials.c polynomials/polynomials.h polynomials/list_P.h polynomials/list_P.c)
add_executable(Data_Structures_and_Algorithm_Analysis_in_C ${SOURCE_FILES})