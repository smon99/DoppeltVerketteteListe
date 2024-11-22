cmake_minimum_required(VERSION 3.10)

# Project name
project(DoppeltVerketteteListe)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
add_executable(DoppeltVerketteteListe
        src/main.cpp
        src/AddressManager.cpp
        src/DoublyLinkedList.cpp
)
