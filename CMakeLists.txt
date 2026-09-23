cmake_minimum_required(VERSION 4.3)
project(pointersPractice)

set(CMAKE_CXX_STANDARD 20)

add_executable(pointersPractice main.cpp
        ArrayList.h
        Node.h
        LinkedList.h
        List.h
        Data.h)
