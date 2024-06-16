cmake_minimum_required(VERSION 3.27)
project(Project4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project4 main.cpp
        Interface.cpp
        Interface.h
        Database.cpp
        Database.h
        Folder.cpp
        Folder.h
        Note.cpp
        Note.h
)
