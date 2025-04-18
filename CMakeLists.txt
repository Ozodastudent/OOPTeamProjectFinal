cmake_minimum_required(VERSION 3.28)
project(OOPEmployeeManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPEmployeeManagement main.cpp
        Employee.h
        Employee.cpp
        Set.h)
