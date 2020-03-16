cmake_minimum_required(VERSION 3.15)
project(SDIZO_Projekt_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SDIZO_Projekt_1
        InputData/
        OutputData/Array/
        OutputData/DoublyLinkedList/
        OutputData/Heap/
        OutputData/BinarySearchTree/
        Array.cpp
        Array.h
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Heap.cpp
        Heap.h
        Menu.cpp
        Test.cpp
        Test.h
        Time.cpp
        Time.h
        ElementsDLL.cpp
        ElementsDLL.h
        RandomInputDataGenerator.cpp
        RandomInputDataGenerator.h)
