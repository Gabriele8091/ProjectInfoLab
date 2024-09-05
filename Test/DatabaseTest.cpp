#include "Database.h"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>

class DatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        originalCinBuffer = std::cin.rdbuf();
        originalCoutBuffer = std::cout.rdbuf();
    }

    void TearDown() override {
        std::cin.rdbuf(originalCinBuffer);
        std::cout.rdbuf(originalCoutBuffer);
    }

    std::streambuf* originalCinBuffer;
    std::streambuf* originalCoutBuffer;
};


TEST_F(DatabaseTest, CreateFolder) {
    Database db;
    std::istringstream simulatedInputFolder("New Folder\n");
    std::cin.rdbuf(simulatedInputFolder.rdbuf());
    db.createFolder();

    Folder* folder = db.getFolder(1);
    ASSERT_NE(folder, nullptr);
    EXPECT_EQ(folder->getFolderId(), 1);
}
TEST_F(DatabaseTest, RemoveFolder) {
    Database db;
    std::istringstream simulatedInputFolder("New Folder\n");
    std::cin.rdbuf(simulatedInputFolder.rdbuf());
    db.createFolder();


    std::istringstream simulatedInput("1\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    db.removeFolder();


    Folder* folder = db.getFolder(1);
    EXPECT_EQ(folder, nullptr);
}

