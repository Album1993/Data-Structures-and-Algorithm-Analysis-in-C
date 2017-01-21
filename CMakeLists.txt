cmake_minimum_required(VERSION 3.6)
project(Data_Structures_and_Algorithm_Analysis_in_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LinkedList/list.c
                LinkedList/list.h
                main.c
        fatal.h
        LinkedList/testlist.c
        LinkedList/testlist.h
        polynomials/polynomials.c
        polynomials/polynomials.h
        polynomials/list_P.h
        polynomials/list_P.c
        polynomials/polynomials_List.c
        polynomials/polynomials_List.h
        Cursor/cursor.c
        Cursor/cursor.h
        Cursor/testCurs.c
        Cursor/testCurs.h
        stackar/stackar.c
        stackar/stackar.h
        stackar/teststka.c
        stackar/teststka.h
        stackli/stackli.c
        stackli/stackli.h
        stackli/testStackli.c
        stackli/testStackli.h
        queue/queue.c
        queue/queue.h
        queue/testQueue.c
        queue/testQueue.h
        binarySearchTree/tree.c
        binarySearchTree/tree.h
        binarySearchTree/testTree.c
        binarySearchTree/testTree.h
        avltree/avltree.c
        avltree/avltree.h avltree/testavltree.c avltree/testavltree.h hashfunc/hashfunc.c hashfunc/hashfunc.h hashsep/hashsep.c hashsep/hashsep.h hashsep/testhash.c hashsep/testhash.h hashquad/hashquad.c hashquad/hashquad.h binheap/binheap.c binheap/binheap.h binheap/testheap.c binheap/testheap.h leftheap/leftheap.c leftheap/leftheap.h leftheap/testleftheap.c leftheap/testleftheap.h sort/sort.c sort/sort.h)
add_executable(Data_Structures_and_Algorithm_Analysis_in_C ${SOURCE_FILES})