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
        DatabaseTest.cpp
        FolderTest.cpp
        ${CMAKE_SOURCE_DIR}/Database.cpp
        ${CMAKE_SOURCE_DIR}/Folder.cpp
        ${CMAKE_SOURCE_DIR}/Note.cpp
        ${CMAKE_SOURCE_DIR}/NoteCounterNotifier.cpp
        NoteTest.cpp


)
target_link_libraries(
        runAllTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runAllTests)