include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        runAllTests
        runAllTests.cpp
        NoteTest.cpp
        Note.h
        Database.h
        Folder.h
        Interface.h
        Subject.h
        Observer.h
        NoteCounterNotifier.h
        Note.cpp
        NoteCounterNotifier.cpp
        Database.cpp
        Folder.cpp
        Interface.cpp
        FolderTest.cpp
        DatabaseTest.cpp

)
target_link_libraries(
        runAllTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runAllTests)