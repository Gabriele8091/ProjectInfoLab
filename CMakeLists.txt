CMAKE_MINIMUM_REQUIRED(VERSION 3.27)

project(Project4)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(Test)

add_executable(Project4 main.cpp
        Interface.cpp
        Interface.h
        Database.cpp
        Database.h
        Folder.cpp
        Folder.h
        Note.cpp
        Note.h
        Subject.h
        Observer.h
        NoteCounterNotifier.cpp
        NoteCounterNotifier.h
        )


